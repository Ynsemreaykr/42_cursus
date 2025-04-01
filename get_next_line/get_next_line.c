/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:59:46 by yayiker           #+#    #+#             */
/*   Updated: 2025/03/03 09:59:47 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_function(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getrest(buffer);
	return (line);
}

char	*read_function(int fd, char *buffer)
{
	char	*tmp;
	int		len;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	len = 1;
	while (!ft_strchr(buffer, '\n') && (len != 0))
	{
		len = read(fd, tmp, BUFFER_SIZE);
		if (len == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[len] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getrest(char *buffer)
{
	int		i;
	int		j;
	char	*restof;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		restof[j++] = buffer[i++];
	restof[j] = '\0';
	free(buffer);
	return (restof);
}
