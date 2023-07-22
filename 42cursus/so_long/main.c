/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/07/22 18:37:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*c;
	void	*g;
	void	*w;
	size_t	fd;
	int		x;
	int		y;
	int		wi;
	int		he;
	int		win_width;
	int		win_height;
}	t_param;

#define KEY_ESC			53
#define KEY_W				13
#define KEY_S				1
#define KEY_A				0
#define KEY_D				2
#define PRESS_RED_BUTTON	17

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->he;
	if (keycode == KEY_S && param->y != 480)
		param->y += param->he;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->wi;
	else if (keycode == KEY_D && param->x != 480)
		param->x += param->wi;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, loc->x, loc->y);
	return (0);
}

int	main(void)
{
	t_param		par;

	par.mlx = mlx_init();
	par.c = mlx_xpm_file_to_image(par.mlx, "./img/hhh.xpm", &par.wi, &par.he);
	par.win = mlx_new_window(par.mlx, 1000, 1000, "DrawMap");
	par.x = 0;
	par.y = 0;
	mlx_key_hook(par.win, &key_press, &par);
	mlx_loop_hook(par.mlx, &draw, &par);
	mlx_loop(par.mlx);
	return (0);
}

// gcc -I. -L./mlx -lmlx -framework OpenGL -framework Appkit main.c