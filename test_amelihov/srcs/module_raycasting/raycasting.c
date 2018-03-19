/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:11:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/09 18:11:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <math.h>

#define X 0
#define Y 1

static t_side 	determinate_side(t_vect2d ray_dir, t_vect2d hit)
{
	short	hit_vertical_side;
	short	hit_horizontal_side;

	hit_horizontal_side = ((int)hit[Y] == hit[Y]) ? 1 : 0;
	hit_vertical_side = ((int)hit[X] == hit[X]) ? 1 : 0;
	if (hit_horizontal_side)
	{
		if (ray_dir >= 0)
			return (west);
		return (east);
	}
	else 
	{
		if (ray_dir >= 0)
			return (south);
		return (north);
	}
}

static t_vect2i	get_coord_on_map(t_vect2d pos, t_vect2d ray_dir)
{
	t_vect2i	coord_on_map;

	coord_on_map[X] = (int)pos[X];
	coord_on_map[Y] = (int)pos[Y];
	if ((pos[X] == (int)pos[X]) && ray_dir[X] < 0)
		coord_on_map[X] = coord_on_map[X] - 1;
	if ((pos[Y] == (int)pos[Y]) && ray_dir[Y] < 0)
		coord_on_map[Y] = coord_on_map[Y] - 1;
	return (coord_on_map);
}

static t_vect2d	step_on_map(t_vect2d dir, t_vect2d pos)
{
	t_vect2d	offset_to_side;
	t_vect2d	step;

	if (dir[X] > 0)
		offset_to_side[X] = fabs((int)(pos[X] + 1) - pos[X]);
	else
		offset_to_side[X] = -1 * fabs(ceil(pos[X] - 1) - pos[X]);
	if (dir[Y] > 0)
		offset_to_side[Y] = fabs((int)(pos[Y] + 1) - pos[Y]);
	else
		offset_to_side[Y] = -1 * fabs(ceil(pos[Y] - 1) - pos[Y]);
	if (fabs(dir[Y] * offset_to_side[X]) < fabs(offset_to_side[Y] * dir[X]))
	{
		step[X] = offset_to_side[X];
		step[Y] = step[X] * dir[Y] / dir[X];
	}
	else
	{
		step[Y] = offset_to_side[Y];
		step[X] = step[Y] * dir[X] / dir[Y];
	}
	return (step);
}

#define FLOOR 0
#define SQ(x) ((x) * (x))
#define GET_DIST_BETWEEN(v1, v2) (sqrt(SQ(v1[X] - v2[X]) + SQ(v1[Y] - v2[Y])))

void			cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map *map, t_hit *hit)
{
	t_vect2i	coord_on_map;
	t_vect2d 	curr_pos;

	coord_on_map[X] = (int)pos[X];
	coord_on_map[Y] = (int)pos[Y];
	curr_pos = pos;
	while (map->coord[coord_on_map[Y]][coord_on_map[X]] == FLOOR)
	{
		curr_pos += step_on_map(ray_dir, curr_pos);
		coord_on_map = get_coord_on_map(curr_pos, ray_dir);
	}
	hit->hit_point = curr_pos;
	hit->pos_on_map = coord_on_map;
	hit->value_on_map = map->coord[coord_on_map[Y]][coord_on_map[X]];
	hit->ray_len = GET_DIST_BETWEEN(pos, hit_point);
	hit->side = determinate_side(ray_dir, hit_point);
}
