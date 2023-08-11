/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:19:51 by haekang           #+#    #+#             */
/*   Updated: 2023/08/11 17:10:47 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_file(t_info *info, char *ber_file)
{
	char	*file_name_extention;
	char	*path;
	char	*tmp;

	file_name_extention = ".ber";
	path = ft_strjoin("./maps/", ber_file);
	tmp = ft_strrchr(path, '.');
	if (ft_strncmp(tmp, file_name_extention, 5) == 0)
	{
		info->fd = open(path, O_RDONLY);
		if (info->fd < 0)
		{
			ft_printf("Error\n>파일이 없거나 열리지 않습니다.\n");
			free(path);
			exit(1);
		}
		free(path);
	}
	else
	{
		ft_printf("Error\n>파일이 없거나 확장자가 잘못 됐습니다.\n");
		free(path);
		exit(1);
	}
}

static void	check_map_line(char *save, t_info *info)
{
	int	i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			if (save[i + 1] == '\n')
			{
				ft_printf("Error\n>맵에 줄바꿈이 있습니다.\n");
				free(save);
				close(info->fd);
				exit(1);
			}
		}
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
	check_map_line(save, info);
	info->map_data = ft_split(save, '\n');
	free(save);
	if (info->map_data[0] == NULL)
		print_and_err_exit("Error\n>맵이 빈 파일 입니다.\n", info);
	handle_err_map_data(info);
	if (info->max_x > WIN_MAX_X || info->max_y > WIN_MAX_Y)
		print_and_err_exit("Error\n>화면이 너무 큽니다.\n", info);
	info->win = mlx_new_window(info->mlx, info->max_x * 64, \
								info->max_y * 64, "so_long");
}

void	set_info(t_info *info, char *ber_file)
{
	open_file(info, ber_file);
	info->mlx = mlx_init();
	info->win = NULL;
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
	{
		ft_printf("Error\n>존재하지 않는 이미지 파일이 있습니다.\n");
		close(info->fd);
		exit(1);
	}
	info->cnt_c = 0;
	info->cnt_p = 0;
	info->cnt_e = 0;
	info->cnt_step = 0;
	set_map_data(info);
}
