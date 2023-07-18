/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/19 07:20:16 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(t_pipex *info)
{
	if (close(info->infile) == -1)
		perror("close failed");
	if (close(info->pipefd[1]) == -1)
		perror("close failed");
	if (close(info->outfile) == -1)
		perror("close failed");
	if (close(info->pipefd[0]) == -1)
		perror("close failed");
}

static void	first_child(t_pipex *info, char **envp)
{
	char	*cmd1_path;

	cmd1_path = find_cmd_abspath(info->path, info->cmd1_av[0]);
	if (cmd1_path == NULL)
		write_error_and_exit("error cmd1: command not found\n");
	if (dup2(info->infile, STDIN_FILENO) == -1)
		perror_and_exit("dup2 failed");
	if (dup2(info->pipefd[1], STDOUT_FILENO) == -1)
		perror_and_exit("dup2 failed");
	close_fd(info);
	if (execve(cmd1_path, info->cmd1_av, envp) == -1)
		perror_and_exit("execve failed");
}

static void	second_child(t_pipex *info, char **envp)
{
	char	*cmd2_path;

	cmd2_path = find_cmd_abspath(info->path, info->cmd2_av[0]);
	if (cmd2_path == NULL)
		write_error_and_exit("error cmd2: command not found\n");
	if (dup2(info->pipefd[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2 failed");
	if (dup2(info->outfile, STDOUT_FILENO) == -1)
		perror_and_exit("dup2 failed");
	close_fd(info);
	if (execve(cmd2_path, info->cmd2_av, envp) == -1)
		perror_and_exit("execve failed");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*info;
	int		pid1;
	int		pid2;

	if (ac != 5)
		write_error_and_exit("wrong number of arguments\n");
	info = set_info(av, envp);
	pid1 = fork();
	if (pid1 == -1)
		perror_and_exit("fork failed");
	if (pid1 == 0)
		first_child(info, envp);
	pid2 = fork();
	if (pid2 == -1)
		perror_and_exit("fork failed");
	if (pid2 == 0)
		second_child(info, envp);
	info_free(info);
	if (wait(NULL) == -1)
		perror_and_exit("wait function failed");
	if (wait(NULL) == -1)
		perror_and_exit("wait function failed");
	return (0);
}
