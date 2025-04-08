/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:18:47 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:18:48 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_tot(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n != 0)
		i--;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_iitoa(int n)
{
	int		i;
	char	*c;

	i = ft_count(n);
	c = (char *) malloc((i + 2) * sizeof(char));
	if (!c)
		return (NULL);
	c[i + 1] = '\0';
	if (n == 0)
		c[i] = '0';
	if (n < 0)
		c[0] = '-';
	while (n != 0)
	{
		c[i--] = ft_tot(n % 10) + '0';
		n /= 10;
	}
	return (c);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		i;

	s = ft_iitoa(n);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	free(s);
	return (i);
}
