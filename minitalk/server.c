/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:26:44 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/01 23:20:38 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 10)
	{
		num += 48;
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

void	ft_handle(int sig)
{
	static int	a = 128;
	static char	c = 0;

	if (sig == SIGUSR1)
		c += a;
	a = a / 2;
	if (a == 0)
	{
		write(1, &c, 1);
		a = 128;
		c = 0;
	}
}

int	main(void)
{
	write(1, "PID:", 4);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
	return (0);
}
