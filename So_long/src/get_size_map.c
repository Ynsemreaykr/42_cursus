/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:35:39 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:35:40 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	strlen_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	read_and_sum_lines(int fd, int *col_len)
{
	char	*line;
	int		total_len;

	total_len = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error: Empty map file\n");
		exit(0);
	}
	*col_len = strlen_no_newline(line);
	total_len += *col_len;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		total_len += strlen_no_newline(line);
		free(line);
	}
	return (total_len);
}

int	get_col_size(int fd)
{
	int	col_len;
	int	total_len;

	total_len = read_and_sum_lines(fd, &col_len);
	if (col_len == 0 || total_len % col_len != 0)
	{
		ft_printf("Error: The map is not rectangular\n");
		exit(0);
	}
	return (col_len);
}

int	get_line_size(int fd)
{
	char	*c;
	int		x;

	x = 0;
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		x++;
		free(c);
	}
	if (x == 0)
	{
		ft_printf("Error: The file is empty or not exist\n");
		exit(0);
	}
	return (x);
}
