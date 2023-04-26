/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:06:21 by haekang           #+#    #+#             */
/*   Updated: 2023/04/09 17:29:01 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (fd < 0 || s == NULL)
		return ;
	while (i < len)
		write(fd, (s + i++), 1);
}
