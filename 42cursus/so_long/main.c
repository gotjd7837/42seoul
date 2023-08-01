/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/01 21:15:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*c;
	void	*g;
	void	*w;
	void	*e;
	int		fd;
	char	**map_data;
	int		x;
	int		y;
	int		wi;
	int		he;
	int		win_width;
	int		win_height;
}	t_info;

#define KEY_ESC			53
#define KEY_W				13
#define KEY_S				1
#define KEY_A				0
#define KEY_D				2
#define PRESS_RED_BUTTON	17

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W && info->y != 0)
		info->y -= info->he;
	if (keycode == KEY_S && info->y <= 436)
		info->y += info->he;
	else if (keycode == KEY_A && info->x != 0)
		info->x -= info->wi;
	else if (keycode == KEY_D && info->x <= 436)
		info->x += info->wi;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", info->y, info->x);
	return (0);
}

void	init_img(t_info *info)
{
	char	*top = "111111";
	char	*mid = "1C0001";
	char	*bottom = "111111";
	int x = 0;
	int y = 0;

	while (*top)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		top++;
		x++;
	}
	x = 0;
	y = 1;
	while (*mid)
	{
		if (*mid == '1')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		}
		else if (*mid == 'C')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->c, x * 64, y * 64);
			info->x = x * 64;
			info->y = y * 64;
		}
		else if (*mid == '0')
			mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mid++;
		x++;
	}
	x = 0;
	y = 2;
	while (*bottom)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		bottom++;
		x++;
	}
}

int	draw(t_info *info)
{
	// mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->c, info->x, info->y);
	return (0);
}

void	set_map(t_info *info)
{
	char	*tmp;
	char	*line;
	char	*save;
	int		x_len;
	int		y_len;

	save = ft_strdup("");
	while (1)
	{
		line = get_next_line(info->fd);
		if (line == NULL)
			break ;
		tmp = save;
		save = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	info->map_data = ft_split(save, '\n');
	x_len = ft_strlen(info->map_data[0]);
	y_len = 0;
	while (*info->map_data++)
		y_len++;
	info->win = mlx_new_window(info->mlx, x_len * 64, y_len * 64, "so_long");
}

void	set_info(t_info *info, char *ber_file)
{
	info->mlx = mlx_init();
	info->c = mlx_xpm_file_to_image(info->mlx, "./imgs/basic.xpm", \
									&info->wi, &info->he);
	info->w = mlx_xpm_file_to_image(info->mlx, "./imgs/wall.xpm", \
									&info->wi, &info->he);
	info->g = mlx_xpm_file_to_image(info->mlx, "./imgs/grass.xpm", \
									&info->wi, &info->he);
	info->e = mlx_xpm_file_to_image(info->mlx, "./imgs/exit.xpm", \
									&info->wi, &info->he);
	info->fd = open(ber_file, O_RDONLY);
	set_map(info);
	init_img(info);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac == 2)
	{
		set_info(&info, av[1]);
		mlx_key_hook(info.win, key_press, &info);
		mlx_loop_hook(info.mlx, draw, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}

// gcc -I. -L./mlx -lmlx -framework OpenGL -framework Appkit main.c