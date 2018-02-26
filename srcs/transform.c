/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:12:13 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 18:04:18 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

#define DIR_STEP 0.5
#define ROTATE_ANGLE 4.0 * M_PI / 180.0
#define MOTION_FORWARD 	0b00000001
#define MOTION_BACKWARD	0b00000010
#define ROTATION_LEFT  	0b00000001
#define ROTATION_RIGHT 	0b00000010

void	move(t_player *hero, t_map *map, t_byte motion)
{
	t_vect2d	delta;
	float		step;

	if (motion == MOTION_FORWARD)
		step = DIR_STEP;
	else if (motion == MOTION_BACKWARD)
		step = -DIR_STEP;
	else
		return ;
	delta = hero->dir * (t_vect2d){step, step};
	if (!map->coord[(int)(hero->pos + delta)[Y]][(int)(hero->pos + delta)[X]])
	{
		hero->pos[X] += delta[X];
		hero->pos[Y] += delta[Y];
	}
}

void	rotate(t_player *hero, t_map *map, t_byte rotation)
{
	t_vect2d	new_dir;
	t_vect2d	new_plane;
	float		angle;

	if (rotation == ROTATION_RIGHT)
		angle = -ROTATE_ANGLE;
	else if (rotation == ROTATION_LEFT)
		angle = ROTATE_ANGLE;
	else
		return ;
	new_dir[X] = hero->dir[X] * cos(angle) - hero->dir[Y] * sin(angle);
	new_dir[Y] = hero->dir[X] * sin(angle) + hero->dir[Y] * cos(angle);
	new_plane[X] = hero->plane[X] * cos(angle) - hero->plane[Y] * sin(angle);
	new_plane[Y] = hero->plane[X] * sin(angle) + hero->plane[Y] * cos(angle);
	hero->dir = new_dir;
	hero->plane = new_plane;
}
