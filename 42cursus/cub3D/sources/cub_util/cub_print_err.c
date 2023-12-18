/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_print_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:11:06 by haekang           #+#    #+#             */
/*   Updated: 2023/12/18 17:11:24 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_print_err(char *str)
{
	write(2, "\033[0;35mError\n", cub_strlen("\033[0;35mError\n"));
	write(2, str, cub_strlen(str));
	write(2, "\033[0;0m", cub_strlen("\033[0;0m"));
	exit(1);
}
