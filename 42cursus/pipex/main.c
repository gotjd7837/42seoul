/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/14 20:06:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_error_pid2(t_pipex *info)
{
	if (info->outfile == -1)
		print_error("outfile open fail");
	if (info->path_cmd2 == NULL)
		print_error("cmd2 not found");
}

static void	handle_error_pid1(t_pipex *info)
{
	if (info->infile == -1)
		print_error("infile open fail");
	if (info->path_cmd1 == NULL)
		print_error("cmd1 not found");
}

static void	write_to_pipe(t_pipex *info, char **envp)
{
	handle_error_pid1(info);
	close(info->pipefd[0]);
	dup2(info->infile, STDIN_FILENO);
	dup2(info->pipefd[1], STDOUT_FILENO);
	close(info->infile);
	close(info->pipefd[1]);
	close(info->outfile);
	execve(info->path_cmd1, info->cmd1, envp);
}

static void	read_from_pipe(t_pipex *info, char **envp)
{
	handle_error_pid2(info);
	dup2(info->pipefd[0], STDIN_FILENO);
	dup2(info->outfile, STDOUT_FILENO);
	close(info->pipefd[0]);
	close(info->outfile);
	close(info->infile);
	execve(info->path_cmd2, info->cmd2, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*info;
	int		pid1;
	int		pid2;

	if (ac != 5)
		print_error("ac error");
	info = set_info(av, envp);
	pid1 = fork();
	if (pid1 == 0)
		write_to_pipe(info, envp);
	close(info->pipefd[1]);
	pid2 = fork();
	if (pid2 == 0)
		read_from_pipe(info, envp);
	close(info->pipefd[0]);
	while (wait(NULL) != -1)
		;
	exit(0);
}
