/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:30:09 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:30:10 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	check_args(char **argv)
{
	int		len;
	char	*filename;

	filename = ft_strrchr(argv[1], '/');
	if (filename)
		filename++;
	else
		filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4
		|| ft_strncmp(filename + len - 4, ".ber", 4) != 0
		|| ft_strncmp(filename, ".ber", 4) == 0)
	{
		ft_printf("Error: Incorrect filename\n");
		exit(0);
	}
}

static void	ft_walls(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	while (game->map[i])
	{
		c = 0;
		while (game->map[i][c])
		{
			if (game->map[0][c] != '1'
				|| game->map[game->line - 1][c] != '1')
				ft_exit("Error: The map is not surrounded by walls", game);
			if (game->map[i][0] != '1'
				|| game->map[i][game->col - 1] != '1')
				ft_exit("Error: The map is not surrounded by walls", game);
			c++;
		}
		i++;
	}
}

void	valid_map(t_game *game)
{
	int	col;
	int	line;
	int	size;

	col = 0;
	line = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[line] != 0)
	{
		col = ft_strlen(game->map[line]);
		if (col != size)
			ft_exit("Error: Your map is not rectangular", game);
		line++;
	}
	ft_walls(game);
}

static void	check_char(t_game *game, char c, int line, int col)
{
	if (c == 'C')
		game->score++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->player_x = col;
		game->player_y = line;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		ft_exit("Error: Invalid characters", game);
}

void	check_map(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			check_char(game, game->map[line][col], line, col);
			col++;
		}
		line++;
	}
	if (game->score == 0)
		ft_exit("Error: There's no sushi", game);
	else if (game->exit == 0)
		ft_exit("Error: There's no box", game);
	else if (game->exit > 1)
		ft_exit("Error: Just one box per map", game);
	else if (game->player == 0)
		ft_exit("Error: There's no Mya", game);
	else if (game->player > 1)
		ft_exit("Error: Just one Mya per map", game);
}
