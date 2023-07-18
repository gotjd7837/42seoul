/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:20:04 by haekang           #+#    #+#             */
/*   Updated: 2023/07/19 07:40:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
				perror_and_exit("malloc error");
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
		perror_and_exit("malloc error");
	info->infile = open(av[1], O_RDONLY);
	if (info->infile == -1)
		perror_and_exit("infile error");
	info->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile == -1)
		perror_and_exit("outfile error");
	if (pipe(info->pipefd) == -1)
		perror_and_exit("pipe create fail");
	info->cmd1_av = ft_split(av[2], ' ');
	if (info->cmd1_av == NULL)
		perror_and_exit("malloc error");
	info->cmd2_av = ft_split(av[3], ' ');
	if (info->cmd2_av == NULL)
		perror_and_exit("malloc error");
	info->path = find_path(envp);
	if (info->path == NULL)
		perror_and_exit("malloc error");
	return (info);
}
