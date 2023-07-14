/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:19 by haekang           #+#    #+#             */
/*   Updated: 2023/07/15 03:53:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_and_exit(char *str)
{
	perror(str);
	exit(1);
}

void	write_error_and_exit(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	exit(1);
}
