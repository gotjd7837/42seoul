/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:19:51 by haekang           #+#    #+#             */
/*   Updated: 2023/08/03 21:34:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_map_data(t_info *info)
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
	handle_err_map_data(info);
	//맵 크기 제한 해야함 !
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
	info->cnt_step = 0;
	set_map_data(info);
}
