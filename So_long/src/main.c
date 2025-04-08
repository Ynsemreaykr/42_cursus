/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:59:30 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 23:25:26 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include "../minilibx/mlx.h"
#include <unistd.h>
#include "../libft/libft.h"

static void	start_map(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_box = 0;
	game->exit = 0;
	game->player = 0;
	game->line = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
}

static void	initialize_game(t_game *game, char **argv)
{
	int	fd;
	int	fd_x;
	int	fd_y;
	int	fd_map;

	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	fd_map = open(argv[1], O_RDONLY);
	check_args(argv);
	start_map(game);
	game->line = get_line_size(fd_y);
	game->col = get_col_size(fd_x);
	fd = open(argv[1], O_RDONLY);
	get_maps(game, fd);
	start_validations(game, fd_map);
	close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
}

static void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * 64,
			game->line * 64, "So_long");
	mlx_hook(game->win, 02, 1L, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	put_images(game);
	render_img(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (argc != 2)
	{
		ft_printf("Error: Invalid argument input\n");
		return (0);
	}
	initialize_game(&game, argv);
	player_position(&game);
	start_game(&game);
}
