/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:38:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/02 20:38:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	game_init_failure(t_game *game, char *err)
{
	game_deinit(game);
	try_set_err(err);
}

void		game_deinit(t_game *game)
{
	map_deinit(&game->map);
}

short		game_init(t_game *game)
{
	if (map_init(&game->map) != SUCCESS)
	{
		game_init_failure(game, INIT_MAP_FAILURE);
		return (FAILURE);
	}
	player_init(&game->player);
	return (SUCCESS);
}
