/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:06:21 by haekang           #+#    #+#             */
/*   Updated: 2023/04/26 19:02:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);

void	ft_putstr(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return ;
	while (i < len)
		write(1, (s + i++), 1);
}
