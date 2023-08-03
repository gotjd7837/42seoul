/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:56:00 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 19:57:07 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_d_i(va_list ap)
{
	char	*str;
	int		num;
	int		res;

	num = (int)va_arg(ap, int);
	str = ft_itoa(num);
	ft_putstr(str);
	res = ft_strlen(str);
	free(str);
	return (res);
}
