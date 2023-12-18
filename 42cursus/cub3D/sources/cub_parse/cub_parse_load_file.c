/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_load_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:12:07 by haekang           #+#    #+#             */
/*   Updated: 2023/12/18 17:17:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*cub_parse_load_file_read(int fd)
{
	t_map	*map;
	char	*line;
	int		gnl;

	map = cub_parse_init_map();
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		cub_parse_read_line(map, line);
		free(line);
	}
	if (gnl == -1)
		cub_print_err("Map file read error\n");
	cub_parse_read_line(map, line);
	free(line);
	return (map);
}

t_map	*cub_parse_load_file(char *map_path)
{
	int		fd;
	t_map	*map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		cub_print_err("Map file open error\n");
	map = cub_parse_load_file_read(fd);
	close(fd);
	return (map);
}
