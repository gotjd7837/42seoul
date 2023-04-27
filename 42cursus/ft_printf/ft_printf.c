/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:14 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 20:08:52 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(const char *format, va_list ap)
{
	int	res;

	res = 0;
	if (*format == 'c')
		res = convert_c(ap);
	else if (*format == 's')
		res = convert_s(ap);
	else if (*format == 'p')
		res = convert_p(ap);
	else if (*format == 'd' || *format == 'i')
		res = convert_d_i(ap);
	else if (*format == 'u')
		res = convert_u(ap);
	else if (*format == 'x')
		res = convert_x(ap);
	else if (*format == 'X')
		res = convert_big_x(ap);
	else if (*format == '%')
		res = convert_per();
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			res += convert(format, ap);
		}
		else
		{
			ft_putchar(*format);
			res++;
		}
		format++;
	}
	va_end(ap);
	return (res);
}
