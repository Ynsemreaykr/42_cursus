/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:54:38 by yayiker           #+#    #+#             */
/*   Updated: 2025/03/03 09:54:38 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_split(char *arg, char **args, int *k)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		args[(*k)++] = split[j];
		j++;
	}
	free(split);
	return (1);
}

static void	get_count_words(int argc, char **argv, int *total_words)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!count_words(argv[i], ' '))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		*total_words += count_words(argv[i], ' ');
		i++;
	}
}

char	**parse_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		k;
	int		total_words;

	total_words = 0;
	get_count_words(argc, argv, &total_words);
	args = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!args)
		return (NULL);
	k = 0;
	i = 1;
	while (i < argc)
	{
		if (!process_split(argv[i], args, &k))
		{
			free(args);
			return (NULL);
		}
		i++;
	}
	args[k] = NULL;
	return (args);
}
