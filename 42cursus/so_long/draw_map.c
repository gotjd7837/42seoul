/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:27:08 by haekang           #+#    #+#             */
/*   Updated: 2023/08/06 05:47:15 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image_mid(t_info *info, char *mid_data, int line_idx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = line_idx;
	i = 0;
	while (mid_data[i])
	{
		if (mid_data[i] == '1')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		}
		else if (mid_data[i] == '0' || mid_data[i] == 'P')
		{
			// if (mid_data[i] == 'P')
			// 	mid_data[i] = '0';//이부분 지워도될려나
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		}
		else if (mid_data[i] == 'C')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->c, x * 64, y * 64);
		}
		else if (mid_data[i] == 'E')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->e, x * 64, y * 64);
		}
		i++;
		x++;
	}
}

static void	draw_image_t_b(t_info *info, char *data, int line_idx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = line_idx;
	i = 0;
	while (data[i])
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
			draw_image_t_b(info, info->map_data[i], i);
		else if (i == max_line_idx)
			draw_image_t_b(info, info->map_data[i], i);
		else
			draw_image_mid(info, info->map_data[i], i);
		i++;
	}
}
