/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:10:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 21:10:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include <math.h>

#define X 0
#define Y 1
#define FLOOR 0

#define COLIDER_RADIUS	0.2

static int	check_diagonals(t_vect2d new_pos, t_map *map)
{
	t_vect2d	dest;

	dest = new_pos + (t_vect2d){COLIDER_RADIUS, COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){-COLIDER_RADIUS, COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){COLIDER_RADIUS, -COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){-COLIDER_RADIUS, -COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	return (1);
}

static int	check_pos(t_vect2d new_pos, t_map *map)
{
	t_vect2d	dest;

	dest = new_pos + (t_vect2d){COLIDER_RADIUS, 0.0};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){-COLIDER_RADIUS, 0.0};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){0.0, COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){0.0, -COLIDER_RADIUS};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	dest = new_pos + (t_vect2d){COLIDER_RADIUS, 0.0};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
		return (0);
	if (check_diagonals(new_pos, map) == 0)
		return (0);
	return (1);
}

void		move_player(t_game *game, t_byte motion)
{
	float		step;
	t_vect2d	tmp_pos;

	if (motion == MOTION_FORWARD)
		step = game->player.speed;
	else if (motion == MOTION_BACKWARD)
		step = -game->player.speed;
	else
		return ;
	tmp_pos = game->player.pos;
	tmp_pos[X] += game->player.dir[X] * step;
	if (check_pos(tmp_pos, &game->map))
	{
		game->player.pos = tmp_pos;
	}
	else
		tmp_pos[X] -= game->player.dir[X] * step;
	tmp_pos[Y] += game->player.dir[Y] * step;
	if (check_pos(tmp_pos, &game->map))
	{
		game->player.pos = tmp_pos;
	}
}

void		rotate_player(t_game *game, t_byte rotation)
{
	t_vect2d	new_dir;
	float		angle;

	if (rotation == ROTATION_RIGHT)
		angle = ROTATE_ANGLE;
	else if (rotation == ROTATION_LEFT)
		angle = -ROTATE_ANGLE;
	else
		return ;
	new_dir[X] = game->player.dir[X] * cos(angle)
		- game->player.dir[Y] * sin(angle);
	new_dir[Y] = game->player.dir[X] * sin(angle)
		+ game->player.dir[Y] * cos(angle);
	game->player.dir = new_dir;
}
