/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/06 18:42:53 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	leak()
// {
// 	system("leaks so_long");
// }

int	draw(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	draw_map(info);
	mlx_put_image_to_window(info->mlx, info->win, info->p, info->x, info->y);
	return (0);
}

int	main(int ac, char *av[])
{
	// atexit(leak);
	t_info	info;

	if (ac != 2)
		print_and_err_exit("인자 갯수 잘못 넣음\n");
	set_info(&info, av[1]);
	mlx_key_hook(info.win, key_press, &info);
	mlx_loop_hook(info.mlx, draw, &info);
	mlx_loop(info.mlx);
	return (0);
}
