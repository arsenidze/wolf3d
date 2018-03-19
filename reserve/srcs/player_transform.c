/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:10:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 10:10:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

#define X 0
#define Y 1

void	move_player(t_game *game, t_byte motion)
{
	t_vect2d	delta;
	float		step;
	t_vect2d 	destination;

	if (motion == MOTION_FORWARD)
		step = DIR_STEP;
	else if (motion == MOTION_BACKWARD)
		step = -DIR_STEP;
	else
		return ;
	delta = game->player.dir * (t_vect2d){step, step};
	destination = game->player.pos + delta;
	if (!game->map.coord[(int)(destination)[Y]][(int)destination[X]])
	{
		game->player.pos[X] += delta[X];
		game->player.pos[Y] += delta[Y];
	}
}

void	rotate_player(t_game *game, t_byte rotation)
{
	t_vect2d	new_dir;
	t_vect2d	new_plane;
	float		angle;

	if (rotation == ROTATION_RIGHT)
		angle = ROTATE_ANGLE;
	else if (rotation == ROTATION_LEFT)
		angle = -ROTATE_ANGLE;
	else
		return ;
	new_dir[X] = game->player.dir[X] * cos(angle) - game->player.dir[Y] * sin(angle);
	new_dir[Y] = game->player.dir[X] * sin(angle) + game->player.dir[Y] * cos(angle);
	// new_plane[X] = game->player.plane[X] * cos(angle) - game->player.plane[Y] * sin(angle);
	// new_plane[Y] = game->player.plane[X] * sin(angle) + game->player.plane[Y] * cos(angle);
	game->player.dir = new_dir;
	// game->player.plane = new_plane;
}
