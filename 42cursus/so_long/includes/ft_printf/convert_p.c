/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:54:55 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 19:57:12 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_p(va_list ap)
{
	unsigned long	num;

	num = (unsigned long)va_arg(ap, unsigned long);
	write(1, "0x", 2);
	return (2 + ft_memory_base(num, "0123456789abcdef"));
}
