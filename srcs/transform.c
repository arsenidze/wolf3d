/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:12:13 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/28 18:28:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	move(t_player *hero, t_map *map, float step)
{
	t_vect2d	delta;

	delta = hero->dir * (t_vect2d){step, step};

	if (!map->coord[(int)(hero->pos + delta)[X]][(int)(hero->pos + delta)[Y]])
	{
		hero->pos[X] += delta[X];
		hero->pos[Y] += delta[Y];
	}
}

void	rotate(t_player *hero, t_map *map, float angle)
{
	t_vect2d	new_dir;
	t_vect2d	new_plane;

	new_dir[X] = hero->dir[X] * cos(angle) - hero->dir[Y] * sin(angle);
	new_dir[Y] = hero->dir[X] * sin(angle) + hero->dir[Y] * cos(angle);
	new_plane[X] = hero->plane[X] * cos(angle) - hero->plane[Y] * sin(angle);
	new_plane[Y] = hero->plane[X] * sin(angle) + hero->plane[Y] * cos(angle);
	hero->dir = new_dir;
	hero->plane = new_plane;
}
