/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:15:28 by haekang           #+#    #+#             */
/*   Updated: 2023/04/03 11:18:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rcs_putnbr(long value, int fd)
{
	char	buf;

	if (value >= 10)
		rcs_putnbr(value / 10, fd);
	buf = (value % 10) + '0';
	write(fd, &buf, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	value;

	value = (long)n;
	if (fd < 0)
		return ;
	if (value < 0)
	{
		write(fd, "-", 1);
		value = (-1) * value;
	}
	rcs_putnbr(value, fd);
}
