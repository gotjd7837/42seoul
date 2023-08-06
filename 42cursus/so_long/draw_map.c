/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:27:08 by haekang           #+#    #+#             */
/*   Updated: 2023/08/06 16:14:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image_mid(t_info *info, int line_idx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = line_idx;
	i = 0;
	while (info->map_data[y][i])
	{
		if (info->map_data[y][i] == '1')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		}
		else if (info->map_data[y][i] == '0' || info->map_data[y][i] == 'P')
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		else if (info->map_data[y][i] == 'C')
			draw_item_collections(info, &x, &y);
		else if (info->map_data[y][i] == 'E')
			draw_item_exit(info, &x, &y);
		i++;
		x++;
	}
}

static void	draw_image_t_b(t_info *info, int line_idx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = line_idx;
	i = 0;
	while (info->map_data[y][i])
	{
		mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		i++;
		x++;
	}
}

void	draw_map(t_info *info)
{
	int	i;
	int	max_line_idx;

	i = 0;
	while (info->map_data[i++])
		;
	max_line_idx = i - 1;
	i = 0;
	while (info->map_data[i])
	{
		if (i == 0)
			draw_image_t_b(info, i);
		else if (i == max_line_idx)
			draw_image_t_b(info, i);
		else
			draw_image_mid(info, i);
		i++;
	}
}
