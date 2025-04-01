/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:22:56 by yayiker           #+#    #+#             */
/*   Updated: 2024/12/07 18:07:18 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str != '\0')
	{
		len += ft_putchr(*str);
		str++;
	}
	return (len);
}

int	ft_printf(const char *format,...)
{
	int			count;
	int 		tmp;
	va_list		args;
// format ın null kontrolünü yap
	va_start(args, format);// va_list değişkeniniş başlatır. formattan sorna gelen parametreleri okur
	count = 0;
	tmp = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp += ft_print_format(args, *format);
			if(tmp == -1)
				return -1;
			count += tmp;
		}
		else
		{
			count += ft_putchr(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}