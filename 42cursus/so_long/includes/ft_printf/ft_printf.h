/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:29:04 by haekang           #+#    #+#             */
/*   Updated: 2023/04/27 20:05:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		convert_c(va_list ap);
int		convert_d_i(va_list ap);
int		convert_p(va_list ap);
int		convert_per(void);
int		convert_s(va_list ap);
int		convert_u(va_list ap);
int		convert_x(va_list ap);
int		convert_big_x(va_list ap);

void	ft_putchar(char c);
int		ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_memory_base(unsigned long nbr, char *base);
char	*ft_itoa(int n);

int		ft_printf(const char *format, ...);
int		convert(const char *format, va_list ap);

#endif