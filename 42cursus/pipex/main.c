/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/13 18:37:28 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	write_to_pipe(t_pipex *info, char **envp)
{
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

	if (ac != 5)
		print_error("ac error");
	info = init_info(av, envp);
	if (fork() == 0)
		write_to_pipe(info, envp);
	close(info->pipefd[1]);
	if (fork() == 0)
		read_from_pipe(info, envp);
	close(info->pipefd[0]);
	wait(NULL);
	return (0);
}
