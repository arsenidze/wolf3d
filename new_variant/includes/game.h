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

#include "map.h"
#include "player.h"
#include "errors.h"

#define SUCCESS 0
#define FAILURE 1

#define DIR_STEP 0.1
#define ROTATE_ANGLE (2.5 * M_PI / 180.0)
#define MOTION_FORWARD 	0b00000001
#define MOTION_BACKWARD	0b00000010
#define ROTATION_LEFT  	0b00000001
#define ROTATION_RIGHT 	0b00000010

typedef unsigned char	t_byte;

typedef struct			s_game
{
	t_map		map;
	t_player	player;
}						t_game;

short					game_init(t_game *game);
void					game_deinit(t_game *game);
void					move_player(t_game *game, t_byte motion);
void					rotate_player(t_game *game, t_byte rotation);

#endif
