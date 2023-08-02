/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:10:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/02 20:33:56 by haekang          ###   ########.fr       */
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
	void	*p;
	int		fd;
	char	**map_data;
	int		max_x;
	int		max_y;
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
	int	y_idx;
	int	x_idx;

	y_idx = info->y / 64;
	x_idx = info->x / 64;

	if (keycode == KEY_W && info->map_data[y_idx - 1][x_idx] != '1')
	{
		if (info->map_data[y_idx - 1][x_idx] == 'C')
			info->map_data[y_idx - 1][x_idx] = '0';
		// if (info->map_data[y_idx - 1][x_idx] == 'E')
		// 	{
		// 		나가는거 구현해야함
		// 	}
		info->y -= info->he;
	}
	else if (keycode == KEY_S && info->map_data[y_idx + 1][x_idx] != '1')
	{
		if (info->map_data[y_idx + 1][x_idx] == 'C')
			info->map_data[y_idx + 1][x_idx] = '0';
		info->y += info->he;
	}
	else if (keycode == KEY_A && info->map_data[y_idx][x_idx - 1] != '1')
	{
		if (info->map_data[y_idx][x_idx - 1] == 'C')
			info->map_data[y_idx][x_idx - 1] = '0';
		info->x -= info->wi;
	}
	else if (keycode == KEY_D && info->map_data[y_idx][x_idx + 1] != '1')
	{
		if (info->map_data[y_idx][x_idx + 1] == 'C')
			info->map_data[y_idx][x_idx + 1] = '0';
		info->x += info->wi;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", info->y, info->x);
	return (0);
}

void	put_image_mid(t_info *info, char *mid_data, int line_idx)
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
			if (mid_data[i] == 'P')
			{
				mid_data[i] = '0';
				info->x = x * 64;
				info->y = y * 64;
			}
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

void	put_image_bottom(t_info *info, char *bottom_data, int max_line_idx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = max_line_idx;
	i = 0;
	while (bottom_data[i])
	{
		mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		i++;
		x++;
	}
}

void	put_image_top(t_info *info, char *top_data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (top_data[i])
	{
		mlx_put_image_to_window(info->mlx, info->win, info->g, x * 64, y * 64);
		mlx_put_image_to_window(info->mlx, info->win, info->w, x * 64, y * 64);
		i++;
		x++;
	}
}

void	init_img(t_info *info)
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
			put_image_top(info, info->map_data[0]);
		else if (i == max_line_idx)
			put_image_bottom(info, info->map_data[max_line_idx], max_line_idx);
		else
			put_image_mid(info, info->map_data[i], i);
		i++;
	}
}

int	draw(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	init_img(info);
	mlx_put_image_to_window(info->mlx, info->win, info->p, info->x, info->y);
	return (0);
}

void	set_map_data(t_info *info)
{
	char	*tmp;
	char	*line;
	char	*save;

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
	info->max_x = ft_strlen(info->map_data[0]);
	info->max_y = 0;
	while (info->map_data[info->max_y])
		info->max_y++;
	info->win = mlx_new_window(info->mlx, info->max_x * 64, \
								info->max_y * 64, "so_long");
}

void	set_info(t_info *info, char *ber_file)
{
	info->mlx = mlx_init();
	info->p = mlx_xpm_file_to_image(info->mlx, "./imgs/basic.xpm", \
									&info->wi, &info->he);
	info->c = mlx_xpm_file_to_image(info->mlx, "./imgs/egg.xpm", \
									&info->wi, &info->he);
	info->w = mlx_xpm_file_to_image(info->mlx, "./imgs/wall.xpm", \
									&info->wi, &info->he);
	info->g = mlx_xpm_file_to_image(info->mlx, "./imgs/grass.xpm", \
									&info->wi, &info->he);
	info->e = mlx_xpm_file_to_image(info->mlx, "./imgs/exit.xpm", \
									&info->wi, &info->he);
	info->fd = open(ber_file, O_RDONLY);
	set_map_data(info);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac == 2)
	{
		set_info(&info, av[1]);
		init_img(&info);
		mlx_key_hook(info.win, key_press, &info);
		mlx_loop_hook(info.mlx, draw, &info);
		mlx_loop(info.mlx);
	}
	return (0);
}

// gcc -I. -L./mlx -lmlx -framework OpenGL -framework Appkit main.c