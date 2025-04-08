/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:26:49 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:51:52 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_read(int fd, char *src)
{
	char	*buff;
	int		read_bts;
	int		has_newline;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bts = 1;
	has_newline = ft_chr(src, '\n') != NULL;
	while (!has_newline && read_bts != 0)
	{
		read_bts = read(fd, buff, BUFFER_SIZE);
		if (read_bts == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bts] = '\0';
		src = ft_join(src, buff);
		has_newline = ft_chr(src, '\n') != NULL;
	}
	free(buff);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	s = ft_new_line(s);
	return (line);
}
