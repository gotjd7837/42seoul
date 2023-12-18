/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:10:04 by haekang           #+#    #+#             */
/*   Updated: 2023/12/18 17:09:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*cub_parse(char *file_name)
{
	t_map	*map;
	char	*map_path;

	map_path = cub_parse_make_map_path(file_name);
	map = cub_parse_load_file(map_path);
	return (map);
}
