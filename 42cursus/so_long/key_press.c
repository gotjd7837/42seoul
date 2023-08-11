/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:40:40 by haekang           #+#    #+#             */
/*   Updated: 2023/08/11 10:09:24 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	press_d(t_info *info, int x_idx, int y_idx)
{
	if (info->map_data[y_idx][x_idx + 1] == 'C')
	{
		info->map_data[y_idx][x_idx + 1] = '0';
		info->cnt_c -= 1;
		ft_printf(">수집품 획득 !\n 남은 수집품 : %d개\n", info->cnt_c);
	}
	if (info->map_data[y_idx][x_idx + 1] == 'E')
	{
		if (info->cnt_c == 0)
			print_and_exit(">탈출 성공 !!\n");
		else
		{
			ft_printf(">수집품을 더 수집해야 탈출 할 수 있습니다.\n");
			ft_printf(" 남은 수집품 : %d개\n", info->cnt_c);
		}
	}
	info->x += info->wi;
	info->cnt_step += 1;
	ft_printf("걸음 수 : %d\n", info->cnt_step);
}

static void	press_a(t_info *info, int x_idx, int y_idx)
{
	if (info->map_data[y_idx][x_idx - 1] == 'C')
	{
		info->map_data[y_idx][x_idx - 1] = '0';
		info->cnt_c -= 1;
		ft_printf(">수집품 획득 !\n 남은 수집품 : %d개\n", info->cnt_c);
	}
	if (info->map_data[y_idx][x_idx - 1] == 'E')
	{
		if (info->cnt_c == 0)
			print_and_exit(">탈출 성공 !!\n");
		else
		{
			ft_printf(">수집품을 더 수집해야 탈출 할 수 있습니다.\n");
			ft_printf(" 남은 수집품 : %d개\n", info->cnt_c);
		}
	}
	info->x -= info->wi;
	info->cnt_step += 1;
	ft_printf("걸음 수 : %d\n", info->cnt_step);
}

static void	press_s(t_info *info, int x_idx, int y_idx)
{
	if (info->map_data[y_idx + 1][x_idx] == 'C')
	{
		info->map_data[y_idx + 1][x_idx] = '0';
		info->cnt_c -= 1;
		ft_printf(">수집품 획득 !\n 남은 수집품 : %d개\n", info->cnt_c);
	}
	if (info->map_data[y_idx + 1][x_idx] == 'E')
	{
		if (info->cnt_c == 0)
			print_and_exit(">탈출 성공 !!\n");
		else
		{
			ft_printf(">수집품을 더 수집해야 탈출 할 수 있습니다.\n");
			ft_printf(" 남은 수집품 : %d개\n", info->cnt_c);
		}
	}
	info->y += info->he;
	info->cnt_step += 1;
	ft_printf("걸음 수 : %d\n", info->cnt_step);
}

static void	press_w(t_info *info, int x_idx, int y_idx)
{
	if (info->map_data[y_idx - 1][x_idx] == 'C')
	{
		info->map_data[y_idx - 1][x_idx] = '0';
		info->cnt_c -= 1;
		ft_printf(">수집품 획득 !\n 남은 수집품 : %d개\n", info->cnt_c);
	}
	if (info->map_data[y_idx - 1][x_idx] == 'E')
	{
		if (info->cnt_c == 0)
			print_and_exit(">탈출 성공 !!\n");
		else
		{
			ft_printf(">수집품을 더 수집해야 탈출 할 수 있습니다.\n");
			ft_printf(" 남은 수집품 : %d개\n", info->cnt_c);
		}
	}
	info->y -= info->he;
	info->cnt_step += 1;
	ft_printf("걸음 수 : %d\n", info->cnt_step);
}

int	key_press(int keycode, t_info *info)
{
	int	y_idx;
	int	x_idx;

	y_idx = info->y / 64;
	x_idx = info->x / 64;
	if (keycode == KEY_W && info->map_data[y_idx - 1][x_idx] != '1')
		press_w(info, x_idx, y_idx);
	else if (keycode == KEY_S && info->map_data[y_idx + 1][x_idx] != '1')
		press_s(info, x_idx, y_idx);
	else if (keycode == KEY_A && info->map_data[y_idx][x_idx - 1] != '1')
		press_a(info, x_idx, y_idx);
	else if (keycode == KEY_D && info->map_data[y_idx][x_idx + 1] != '1')
		press_d(info, x_idx, y_idx);
	else if (keycode == KEY_ESC)
		print_and_exit(">프로그램 종료\n");
	draw(info);
	return (0);
}
