/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:33:21 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/08 22:35:07 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdbool.h>
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	map_malloc_path(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		y;

	i = 0;
	y = game->line + 1;
	game->map_floodfill = (char **)malloc(sizeof(char *) * y);
	if (!game->map_floodfill)
		free_img(game);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map_floodfill[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

static int	fill(t_game *game, int line, int col)
{
	static int	exit = 0;
	static int	cols = 0;

	if (line < 0 || col < 0 || line >= game->line || col >= game->col)
		return (0);
	else if (game->map_floodfill[line][col] == 'X')
		return (0);
	else if (game->map_floodfill[line][col] == '1')
		return (0);
	else if (game->map_floodfill[line][col] == 'E')
		exit = 1;
	if (game->map_floodfill[line][col] == 'C')
		cols++;
	game->map_floodfill[line][col] = 'X';
	fill(game, line + 1, col);
	fill(game, line, col + 1);
	fill(game, line - 1, col);
	fill(game, line, col - 1);
	return (cols == game->score && exit);
}

static int	floodfill(t_game *game)
{
	int		line;
	int		col;
	int		valid;

	line = game->player_y;
	col = game->player_x;
	valid = fill(game, line, col);
	return (valid);
}

void	valid_path(t_game *game, int fd)
{
	int	is_valid;

	map_malloc_path(game, fd);
	is_valid = floodfill(game);
	if (!is_valid)
	{
		free_map_floodfill(game);
		close(fd);
		ft_exit("Error: Invalid path to on the map", game);
	}
	free_map_floodfill(game);
}
