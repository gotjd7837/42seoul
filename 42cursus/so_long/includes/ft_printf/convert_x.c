/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:58:34 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 20:03:23 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x(va_list ap)
{
	int	num;

	num = (unsigned int)va_arg(ap, unsigned int);
	return (ft_putnbr_base(num, "0123456789abcdef"));
}

int	convert_big_x(va_list ap)
{
	int	num;

	num = (unsigned int)va_arg(ap, unsigned int);
	return (ft_putnbr_base(num, "0123456789ABCDEF"));
}
