/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_make_map_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:08:57 by haekang           #+#    #+#             */
/*   Updated: 2023/12/18 17:10:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_parse_check_filename(char *file_name)
{
	int	len;

	len = cub_strlen(file_name);
	if (len < 4)
		cub_print_err("Invalid file name\n");
	if (file_name[len - 1] != 'b' || file_name[len - 2] != 'u'
		|| file_name[len - 3] != 'c' || file_name[len - 4] != '.')
		cub_print_err("Invalid file name\n");
}

char	*cub_parse_make_map_path(char *file_name)
{
	char	*map_path;

	cub_check_filename(file_name);
	map_path = cub_strjoin("./maps/", file_name);
	if (map_path == NULL)
		cub_print_err("Malloc failed\n");
	return (map_path);
}
