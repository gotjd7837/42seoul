/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:02:23 by haekang           #+#    #+#             */
/*   Updated: 2023/08/06 18:40:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_free(t_check *check)
{
	int	i;

	i = 0;
	while (check->visited[i])
	{
		free(check->visited[i]);
		i++;
	}
	free(check->visited);
}

static void	set_check(t_info *info, t_check *check)
{
	int		i;

	i = 0;
	check->visited = (char **)malloc(sizeof(char *) * (info->max_y + 1));
	while (i < info->max_y)
	{
		check->visited[i] = (char *)malloc(sizeof(char) * (info->max_x + 1));
		ft_memset(check->visited[i], 0, info->max_x + 1);
		i++;
	}
	check->visited[i] = NULL;
	check->cnt_c = 0;
	check->cnt_e = 0;
}

static void	dfs(int x, int y, t_info *info, t_check *check)
{
	if (info->map_data[y][x] == '1')
		return ;
	if (check->visited[y][x] == 0)
	{
		check->visited[y][x] = 1;
		if (info->map_data[y][x] == 'C')
			check->cnt_c++;
		if (info->map_data[y][x] == 'E')
			check->cnt_e++;
		dfs(x, y - 1, info, check);
		dfs(x, y + 1, info, check);
		dfs(x - 1, y, info, check);
		dfs(x + 1, y, info, check);
	}
}

void	check_valid_path(t_info *info)
{
	t_check	check;

	set_check(info, &check);
	dfs((info->x / 64), (info->y / 64), info, &check);
	if (check.cnt_c != info->cnt_c || check.cnt_e != info->cnt_e)
		print_and_err_exit("유효한 경로가 없음\n");
	check_free(&check);
}
