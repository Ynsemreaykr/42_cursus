/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:29:26 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 22:29:27 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

static int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	game->temp = '0';
	if (game->map[line][col] == '1')
		return (-1);
	if (game->map[line][col] == 'C')
		game->score--;
	if (game->map[line][col] == 'E' && game->score > 0)
	{
		game->player_on_box = 1;
		game->temp = 'B';
		return (1);
	}
	if (game->map[line][col] == 'E' && game->score == 0)
	{
		game->end_game = 1;
		ft_printf("\n\nYOU WIN \n\n");
		close_window(game);
	}
	if (pressed_key != W && pressed_key != S
		&& pressed_key != A && pressed_key != D)
		return (-1);
	else
		return (1);
}

static void	move_cat(t_game *game, int col, int line, int pressed_key)
{
	int	valid;
	int	tcol;
	int	tline;

	tcol = game->player_y;
	tline = game->player_x;
	(void)pressed_key;
	valid = valid_move(game, col, line, pressed_key);
	if (valid != -1)
	{
		game->player_y = line;
		game->player_x = col;
		if (game->temp != 'B')
			game->map[line][col] = 'P';
		else
			game->map[line][col] = 'B';
		if (game->map[tcol][tline] != 'B')
			game->map[tcol][tline] = '0';
		else
			game->map[tcol][tline] = 'E';
		ft_printf("Movements: %d\n", game->move++);
		render_img(game);
	}
}

int	key_handler(int keycode, t_game *game)
{
	int	col;
	int	line;

	col = game->player_x;
	line = game->player_y;
	if (keycode == A)
		col--;
	else if (keycode == W)
		line--;
	else if (keycode == S)
		line++;
	else if (keycode == D)
		col++;
	else if (keycode == ESC)
		close_window(game);
	if (game->end_game != 1)
		move_cat(game, col, line, keycode);
	return (0);
}
