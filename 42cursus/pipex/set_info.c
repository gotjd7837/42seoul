/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:20:04 by haekang           #+#    #+#             */
/*   Updated: 2023/07/14 20:05:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*path_cmd;

	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	if (slash_cmd == NULL)
		return (NULL);
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

static char	**find_path(char **envp)
{
	char	*path;
	char	**result;
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
			result = ft_split(path, ':');
			if (result == NULL)
				print_error("malloc error");
			return (result);
		}
		i++;
	}
	return (NULL);
}

t_pipex	*set_info(char **av, char **envp)
{
	t_pipex	*info;

	info = (t_pipex *)malloc(sizeof(t_pipex));
	if (info == NULL)
		print_error("malloc error");
	info->infile = open(av[1], O_RDONLY);
	info->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipe(info->pipefd) == -1)
		print_error("pipe create fail");
	info->cmd1 = ft_split(av[2], ' ');
	if (info->cmd1 == NULL)
		print_error("malloc error");
	info->cmd2 = ft_split(av[3], ' ');
	if (info->cmd2 == NULL)
		print_error("malloc error");
	info->path = find_path(envp);
	if (info->path == NULL)
		print_error("PATH not found");
	info->path_cmd1 = find_cmd_path(info->path, info->cmd1[0]);
	info->path_cmd2 = find_cmd_path(info->path, info->cmd2[0]);
	return (info);
}
