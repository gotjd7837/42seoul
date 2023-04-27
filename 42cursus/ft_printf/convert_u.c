/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:57:24 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 19:58:56 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_u(va_list ap)
{
	char			*str;
	unsigned int	num;
	int				res;

	num = (unsigned int)va_arg(ap, unsigned int);
	str = ft_unsigned_itoa(num);
	ft_putstr(str);
	res = ft_strlen(str);
	free(str);
	return (res);
}
