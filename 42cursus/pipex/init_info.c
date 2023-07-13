/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:20:04 by haekang           #+#    #+#             */
/*   Updated: 2023/07/13 18:32:30 by haekang          ###   ########.fr       */
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

static void	handle_error(t_pipex *info)
{
	if (info->infile == -1)
		print_error("infile open fail");
	if (info->outfile == -1)
		print_error("outfile open fail");
	if (info->cmd1 == NULL)
		print_error("cmd1 split fail");
	if (info->cmd2 == NULL)
		print_error("cmd2 split fail");
	if (info->path == NULL)
		print_error("find_path fail");
	if (info->path_cmd1 == NULL)
		print_error("find_cmd1_path fail");
	if (info->path_cmd2 == NULL)
		print_error("find_cmd2_path fail");
}

t_pipex	*init_info(char **av, char **envp)
{
	t_pipex	*info;

	info = (t_pipex *)malloc(sizeof(t_pipex));
	if (info == NULL)
		return (NULL);
	info->infile = open(av[1], O_RDONLY);
	info->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipe(info->pipefd) == -1)
		print_error("pipe create fail");
	info->cmd1 = ft_split(av[2], ' ');
	info->cmd2 = ft_split(av[3], ' ');
	info->path = find_path(envp);
	info->path_cmd1 = find_cmd_path(info->path, info->cmd1[0]);
	info->path_cmd2 = find_cmd_path(info->path, info->cmd2[0]);
	handle_error(info);
	return (info);
}
