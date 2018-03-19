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
#define FLOOR 0

// void	move_player(t_game *game, t_byte motion)
// {
// 	t_vect2d	delta;
// 	float		step;
// 	t_vect2d 	destination;

// 	if (motion == MOTION_FORWARD)
// 		step = DIR_STEP;
// 	else if (motion == MOTION_BACKWARD)
// 		step = -DIR_STEP;
// 	else
// 		return ;

// 	delta = game->player.dir * (t_vect2d){step, step};
// 	destination = game->player.pos +
// 		game->player.dir * (t_vect2d){1.5 * step, 1.5 * step};

// 	// printf("pos_x: %f pos_y: %f\n", game->player.pos[X], game->player.pos[Y]);
// 	// printf("dest_x: %f dest_y: %f\n", destination[X], destination[Y]);
// 	if (game->map.coord[(int)game->player.pos[Y]][(int)destination[X]] == FLOOR)
// 	{
// 		// printf("test1\n");
// 		game->player.pos[X] += delta[X];
// 	}
// 	if (game->map.coord[(int)destination[Y]][(int)game->player.pos[X]] == FLOOR)
// 	{
// 		// /printf("test2\n");
// 		game->player.pos[Y] += delta[Y];
// 	}
// }

// #define COLIDER_RADIUS 		0.4
// #define COLIDER_RADIUS_ROOT 0.63245553203
#define COLIDER_RADIUS 		0.2
#define COLIDER_RADIUS_ROOT 0.2
// #define COLIDER_RADIUS_ROOT 0.4472135955

static int check_pos(t_vect2d new_pos, t_map *map)
{
	t_vect2d 	dest;

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
 	dest = new_pos + (t_vect2d){COLIDER_RADIUS_ROOT, COLIDER_RADIUS_ROOT};
 	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
 		return (0);
 	dest = new_pos + (t_vect2d){-COLIDER_RADIUS_ROOT, COLIDER_RADIUS_ROOT};
 	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
 		return (0);
 	dest = new_pos + (t_vect2d){COLIDER_RADIUS_ROOT, -COLIDER_RADIUS_ROOT};
 	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
 		return (0);
	dest = new_pos + (t_vect2d){-COLIDER_RADIUS_ROOT, -COLIDER_RADIUS_ROOT};
	if (map->coord[(int)dest[Y]][(int)dest[X]] != FLOOR)
 		return (0);
 	return (1);
}

void	move_player(t_game *game, t_byte motion)
{
	float		step;
	t_vect2d	tmp_pos;

	if (motion == MOTION_FORWARD)
		step = DIR_STEP;
	else if (motion == MOTION_BACKWARD)
		step = -DIR_STEP;
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
	game->player.dir = new_dir;
}
