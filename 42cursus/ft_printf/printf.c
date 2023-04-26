/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:44:14 by haekang           #+#    #+#             */
/*   Updated: 2023/04/26 21:51:21 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
int	ft_putnbr_base(long long nbr, char *base);

int find_format_x(const char *format, va_list ap)
{
    int num;
    int res;

    num = (int)va_arg(ap, int);
    res = ft_putnbr_base(num, "0123456789abcdef");
    return (res);
}

int find_format_u(const char *format, va_list ap)
{
    char *str;
    unsigned int num;

    num = (unsigned int)va_arg(ap, unsigned int);
    str = ft_unsigned_itoa(num);
    ft_putstr(str);
    return (ft_strlen(str)); 
}

int find_format_d_i(const char *format, va_list ap)
{
    char *str;
    int num;

    num = (int)va_arg(ap, int);
    str = ft_itoa(num);
    ft_putstr(str);
    return (ft_strlen(str));
}

int find_format_p(const char *format, va_list ap)
{
    return (1);
}

int find_format_s(const char *format, va_list ap)
{
    char *str;

    str = (char *)va_arg(ap, char *);
    ft_putstr(str);
    return (ft_strlen(str));
}

int find_format_c(const char *format, va_list ap)
{
    char c;

    c = (char)va_arg(ap, int);
    ft_putchar(c);
    return (1);
}

int find_format(const char *format, va_list ap)
{
    int res;

    res = 0;
    if (*format == 'c')
        res = find_format_c(format, ap);
    else if (*format == 's')
        res = find_format_s(format, ap);
    else if (*format == 'p')
        res = find_format_p(format, ap);
    else if (*format == 'd' || *format == 'i')
        res = find_format_d_i(format, ap);
    else if (*format == 'u')
        res = find_format_u(format, ap); //ㅇㅣ부분 엠엠비비알  베베이이스  nbr 자료형 수정해야함 아마 long long으로 ?
    else if (*format == 'x')
        res = find_format_x(format, ap);
    else if (*format == 'X')
        res = printf("%x", va_arg(ap, int));
    else if (*format == '%')
        res = printf("%%");
    return (res);
}

int ft_printf(const char *format, ...) // 반환값 문자열 길이
{
    va_list ap;
    int res;

    res = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            res += find_format(format, ap);
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

int main()
{
    ft_printf("%d", ft_printf("%x, %d\n", 2147483648, 0));

    printf("\n");

    printf("%d", printf("%x, %d\n", 2147483648, 0));
}