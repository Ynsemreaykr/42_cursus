#include "libftprintf.h"
#include <stdio.h>

int	ft_putbinary(unsigned int nbr, unsigned char c)
{
	int	len;

	len = 0;
	if (nbr > 1)
		len += ft_putbinary(nbr / 2, c);
	if (c == 'x')
		len += write(1, &"01"[nbr % 2], 1);
	else
		len += write(1, &"01"[nbr % 2], 1);
	return (len);
}

int main(){

    ft_putbinary(10,'x');


}
