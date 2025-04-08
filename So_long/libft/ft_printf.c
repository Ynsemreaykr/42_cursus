/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:18:09 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:44:23 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_format(va_list args, char specification)
{
	int	x;

	x = 0;
	if (specification == 'i' || specification == 'd')
		x = ft_putnbr(va_arg(args, int));
	else if (specification == 's')
		x = ft_putstr(va_arg(args, char *));
	else if (specification == '%')
		x = ft_putchar('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
