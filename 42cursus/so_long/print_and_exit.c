/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:46:51 by haekang           #+#    #+#             */
/*   Updated: 2023/08/03 21:17:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_and_exit(char *str)
{
	ft_printf(str);
	exit(0);
}

void	print_and_err_exit(char *str)
{
	ft_printf(str);
	exit(1);
}
