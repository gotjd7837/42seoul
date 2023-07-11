/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/11 19:00:23 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


char	*find_path_cmd(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*path_cmd;

	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	while (path[i] != NULL)
	{
		path_cmd = ft_strjoin(path[i], slash_cmd);
		if (access(path_cmd, X_OK) == 0)
		{
			free(slash_cmd);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	return (NULL);
}

char	**find_path(char **envp)
{
	char	*path;
	int		i;
	int		path_len;

	i = 0;
	path = "PATH=";
	path_len = ft_strlen(path);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], path, path_len) == 0)
		{
			path = envp[i] + path_len;
			return (ft_split(path, ':'));
		}
		i++;
	}
	return (NULL);
}

t_pipex	*init_info(char **av, char **envp)
{
	t_pipex	*info;

	info = (t_pipex *)malloc(sizeof(t_pipex));

	info->infile = open(av[1], O_RDONLY);
	info->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipe(info->pipefd);
	info->cmd1 = ft_split(av[2], ' ');
	info->cmd2 = ft_split(av[3], ' ');
	info->path = find_path(envp);
	info->path_cmd1 = find_path_cmd(info->path, info->cmd1[0]);
	info->path_cmd2 = find_path_cmd(info->path, info->cmd2[0]);
	return (info);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*info;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		print_error("ac error");
	info = init_info(av, envp);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(info->pipefd[0]);
		dup2(info->infile, STDIN_FILENO);
		dup2(info->pipefd[1], STDOUT_FILENO);
		close(info->infile);
		close(info->pipefd[1]);
		close(info->outfile);
		execve(info->path_cmd1, info->cmd1, envp);
	}
	close(info->pipefd[1]);
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(info->pipefd[0], STDIN_FILENO);
		dup2(info->outfile, STDOUT_FILENO);
		close(info->pipefd[0]);
		close(info->outfile);
		close(info->infile);
		execve(info->path_cmd2, info->cmd2, envp);
	}
	while (wait(NULL) != -1)
		;
	close(info->pipefd[0]);
	return (0);
}
