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

static void init_game_failure(t_game *game, char *err)
{
	deinit_game(game);
	try_set_err(err);
}

void		deinit_game(t_game *game)
{
	deinit_map(&game->map);
}

short		init_game(t_game *game)
{
	if (init_map(&game->map) != SUCCESS)
	{
		init_game_failure(game, INIT_MAP_FAILURE);
		return (FAILURE);
	}
	init_player(&game->player);
	return (SUCCESS);
}
