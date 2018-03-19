/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:38:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/02 20:38:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "../module_graphics/graphics.h"
#include "../module_map/map.h"
#include "../module_player/player.h"
#include "../module_userinput/userinput.h"

#define SUCCESS 0
#define FAILURE 1

typedef struct	s_game
{
	t_map		map;
	t_player	player;
}				t_game;

short			init_game(t_game *game);
void			deinit_game(t_game *game);
void			update(t_game *game, t_userinput *ui);

#endif
