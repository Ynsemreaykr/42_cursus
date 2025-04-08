/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:47:15 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:47:33 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*start;
	char	*trimmed;
	int		check;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	check = ft_strchr(set, *start) != NULL;
	while (*start && check)
	{
		start++;
		check = ft_strchr(set, *start) != NULL;
	}
	i = ft_strlen(start);
	check = ft_strchr(set, start[i]) != NULL;
	while (i && check)
	{
		i--;
		check = ft_strchr(set, start[i]) != NULL;
	}
	trimmed = ft_substr(start, 0, i + 1);
	return (trimmed);
}
