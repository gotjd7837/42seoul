/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:19:51 by haekang           #+#    #+#             */
/*   Updated: 2023/08/07 21:09:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_file(t_info *info, char *ber_file)
{
	char	*maps_dir;
	char	*file_name_extention;
	char	*path;
	char	*tmp;

	maps_dir = "./maps/";
	file_name_extention = ".ber";
	path = ft_strjoin(maps_dir, ber_file);
	tmp = ft_strrchr(path, '.');
	if (ft_strncmp(tmp, file_name_extention, 4) == 0)
	{
		info->fd = open(path, O_RDONLY);
		if (info->fd < 0)
			print_and_err_exit("Error\n>파일이 없거나 열리지 않습니다.\n");
		free(path);
	}
	else
		print_and_err_exit("Error\n>파일은 '.ber' 확장자를 가져야 합니다.\n");
}

static void	check_map_line(char *save)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			if (save[i + 1] == '\n')
				print_and_err_exit("Error\n>맵 사이에 줄바꿈이 있습니다.\n");
		i++;
	}
}

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
	check_map_line(save);
	info->map_data = ft_split(save, '\n');
	if (info->map_data[0] == NULL)
		print_and_err_exit("Error\n>맵이 빈 파일 입니다.\n");
	free(save);
	handle_err_map_data(info);
	if (info->max_x > WIN_MAX_X || info->max_y > WIN_MAX_Y)
		print_and_err_exit("Error\n>화면이 너무 큽니다.\n");
	info->win = mlx_new_window(info->mlx, info->max_x * 64, \
								info->max_y * 64, "so_long");
}

void	set_info(t_info *info, char *ber_file)
{
	open_file(info, ber_file);
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
	if (info->p == NULL || info->c == NULL || info->w == NULL \
		|| info->g == NULL || info->e == NULL)
		print_and_err_exit("Error\n>존재하지 않는 이미지 파일이 있습니다.\n");
	info->cnt_c = 0;
	info->cnt_p = 0;
	info->cnt_e = 0;
	info->cnt_step = 0;
	set_map_data(info);
}
