/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:46:51 by haekang           #+#    #+#             */
/*   Updated: 2023/08/11 13:40:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	info_free(t_info *info)
{
	int	i;

	i = 0;
	while (info->map_data[i])
	{
		free(info->map_data[i]);
		i++;
	}
	free(info->map_data);
	close(info->fd);
}

void	print_and_exit(char *str, t_info *info)
{
	ft_printf(str);
	info_free(info);
	if (info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	print_and_err_exit(char *str, t_info *info)
{
	ft_printf(str);
	info_free(info);
	if (info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
	exit(1);
}
