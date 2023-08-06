/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:03:41 by haekang           #+#    #+#             */
/*   Updated: 2023/08/06 16:13:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_item_collections(t_info *info, int *x, int *y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g, *x * 64, *y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->c, *x * 64, *y * 64);
}

void	draw_item_exit(t_info *info, int *x, int *y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g, *x * 64, *y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->e, *x * 64, *y * 64);
}

void	draw_item_ground(t_info *info, int *x, int *y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g, *x * 64, *y * 64);
}

void	draw_item_wall(t_info *info, int *x, int *y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->g, *x * 64, *y * 64);
	mlx_put_image_to_window(info->mlx, info->win, info->w, *x * 64, *y * 64);
}
