#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	char		*hex_digit;
	int			len;
	address = (unsigned long)ptr;
	len = 0;
	if(!address)
		ft_putstr("(nil)");
	hex_digit = "0123456789abcdef";
	if (address >= 16)
		len += ft_putptr((void *)(address / 16));
	return (len + ft_putchr(hex_digit[address % 16]));
}

int	ft_print_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (write(1, "0x", 2) + ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchr('%'));
	return (-1);
}

int	ft_puthex(unsigned int nbr, unsigned char c)
{
	int	len;

	len = 0;
	if (nbr > 15)
		len += ft_puthex(nbr / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[nbr % 16], 1);
	else
		len += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchr((n % 10) + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	long		num;
	int			count;

	count = 0;
	num = n;
	if (n < 0)
	{
		count += ft_putchr('-');
		num = -num;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
	}
	else
		count += ft_putchr((num % 10) + '0');
	return (count);
}