/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:34:00 by yayiker           #+#    #+#             */
/*   Updated: 2025/04/06 23:25:00 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_validations(t_game *game, int fd)
{
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
