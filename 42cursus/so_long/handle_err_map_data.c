/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:44:25 by haekang           #+#    #+#             */
/*   Updated: 2023/08/03 21:18:14 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_c_p_e_map(t_info *info)
{
	int	i;
	int	j;

	info->cnt_c = 0;
	info->cnt_p = 0;
	info->cnt_e = 0;
	i = 0;
	while (info->map_data[i])
	{
		j = 0;
		while (info->map_data[i][j])
		{
			if (info->map_data[i][j] == 'P')
				info->cnt_p += 1;
			if (info->map_data[i][j] == 'E')
				info->cnt_e += 1;
			if (info->map_data[i][j] == 'C')
				info->cnt_c += 1;
			j++;
		}
		i++;
	}
}

static void	check_wall_map(t_info *info)
{
	int	bottom_idx;
	int	i;
	int	j;

	i = 0;
	bottom_idx = info->max_y - 1;
	while (info->map_data[i])
	{
		if (i == 0 || i == bottom_idx)
		{
			j = 0;
			while (info->map_data[i][j])
			{
				if (info->map_data[i][j] != '1')
					print_and_err_exit("탑이나 바텀이 벽이 아님 ;;\n");
				j++;
			}
		}
		else
			if (info->map_data[i][0] != '1' || \
				info->map_data[i][info->max_x - 1] != '1')
				print_and_err_exit("맵 미드의 양 끝이 벽이 아닌게 있음 ;;\n");
		i++;
	}
}

static void	set_max_y(t_info *info)
{
	int	max_y;

	max_y = 0;
	while (info->map_data[max_y])
		max_y++;
	info->max_y = max_y;
}

static void	set_max_x(t_info *info)
{
	int	i;
	int	tmp;
	int	max_x;

	i = 0;
	tmp = ft_strlen(info->map_data[0]);
	while (info->map_data[i])
	{
		max_x = ft_strlen(info->map_data[i]);
		if (tmp != max_x)
			print_and_err_exit("맵 사이에 줄바꿈이 있거나 가로 길이가 다름 !\n");
		i++;
	}
	info->max_x = max_x;
}

void	handle_err_map_data(t_info *info)
{
	set_max_x(info);
	set_max_y(info);
	check_wall_map(info);
	check_c_p_e_map(info);
	if (info->cnt_c < 1)
		print_and_err_exit("c가 최소한 1개는 있어야함\n");
	if (info->cnt_e != 1)
		print_and_err_exit("출구는 하나만 있어야함\n");
	if (info->cnt_p != 1)
		print_and_err_exit("플레이어는 하나만 있어야함\n");
	//이제 경로가 유효한지 검사를 한다.
}
