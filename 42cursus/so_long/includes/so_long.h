/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:57:28 by haekang           #+#    #+#             */
/*   Updated: 2023/08/07 16:14:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <fcntl.h>

# define BUFFER_SIZE 		1
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17
# define WIN_MAX_X			40
# define WIN_MAX_Y			21

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
	int		cnt_p;
	int		cnt_e;
	int		cnt_c;
	int		cnt_step;
	int		x;
	int		y;
	int		wi;
	int		he;
	int		win_width;
	int		win_height;
}	t_info;

typedef struct s_check
{
	char	**visited;
	int		cnt_c;
	int		cnt_e;
}	t_check;

char	*get_next_line(int fd);

void	set_info(t_info *info, char *ber_file);

int		draw(t_info *info);
void	draw_map(t_info *info);

void	print_and_err_exit(char *str);
void	print_and_exit(char *str);

int		key_press(int keycode, t_info *info);

void	handle_err_map_data(t_info *info);

void	check_valid_path(t_info *info);

void	draw_item_collections(t_info *info, int *x, int *y);
void	draw_item_exit(t_info *info, int *x, int *y);
void	draw_item_ground(t_info *info, int *x, int *y);
void	draw_item_wall(t_info *info, int *x, int *y);

#endif