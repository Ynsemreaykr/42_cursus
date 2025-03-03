/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:55:14 by yayiker           #+#    #+#             */
/*   Updated: 2025/03/03 09:55:15 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	int		word_count;
	bool	inside_word;

	word_count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				word_count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (word_count);
}

static char	*get_next_word(char *str, char separator, int *k)
{
	char		*next_word;
	int			word_len;
	int			i;

	word_len = 0;
	i = 0;
	while (str[*k] == separator)
		(*k)++;
	while ((str[*k + word_len] != separator) && str[*k + word_len])
		word_len++;
	next_word = malloc((size_t)word_len * sizeof(char) + 1);
	if (next_word == NULL)
		return (NULL);
	while ((str[*k] != separator) && str[*k])
		next_word[i++] = str[(*k)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *str, char separator)
{
	int		word_count;
	char	**result_array;
	int		i;
	int		k;

	k = 0;
	i = 0;
	word_count = count_words(str, separator);
	if (!word_count)
		return (NULL);
	result_array = malloc(sizeof(char *) * (size_t)(word_count + 1));
	if (result_array == NULL)
		return (NULL);
	while (word_count--)
	{
		result_array[i++] = get_next_word(str, separator, &k);
	}
	result_array[i] = NULL;
	return (result_array);
}
