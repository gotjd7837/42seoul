/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 05:02:50 by haekang           #+#    #+#             */
/*   Updated: 2023/07/19 06:55:48 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	arr_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	info_free(t_pipex *info)
{
	if (close(info->infile) == -1)
		perror_and_exit("close failed");
	if (close(info->outfile) == -1)
		perror_and_exit("close failed");
	if (close(info->pipefd[1]) == -1)
		perror_and_exit("close failed");
	if (close(info->pipefd[0]) == -1)
		perror_and_exit("close failed");
	arr_free(info->cmd1_av);
	arr_free(info->cmd2_av);
	arr_free(info->path);
	free(info);
}
