/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/07 21:25:10 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_red_button(t_info *info)
{
	(void)info;
	print_and_exit(">프로그램 종료\n");
	return (0);
}

int	draw(t_info *info)
{
	draw_map(info);
	mlx_put_image_to_window(info->mlx, info->win, info->p, info->x, info->y);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
		print_and_err_exit("Error\n>하나의 맵 파일을 입력하세요\n");
	set_info(&info, av[1]);
	draw(&info);
	mlx_hook(info.win, PRESS_RED_BUTTON, 0, press_red_button, &info);
	mlx_key_hook(info.win, key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
