/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_abspath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 05:24:38 by haekang           #+#    #+#             */
/*   Updated: 2023/07/19 07:06:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*cmd_check(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (cmd);
	write_error_and_exit("no such file or directory\n");
	return (NULL);
}

static int	check_slash(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}

char	*find_cmd_abspath(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*path_cmd;

	if (check_slash(cmd) == 1)
		return (cmd_check(cmd));
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
