/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/11 13:46:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
	{
		ft_printf("Error\n>하나의 맵 파일을 입력하세요\n");
		return (1);
	}
	set_info(&info, av[1]);
	draw(&info);
	mlx_hook(info.win, PRESS_RED_BUTTON, 0, press_red_button, &info);
	mlx_key_hook(info.win, key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
