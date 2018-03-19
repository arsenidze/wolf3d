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

#include <stdio.h>
extern FILE *g_stream;

static t_side 	determinate_side(t_vect2d ray_dir, t_vect2d ray)
{
	short	ray_vertical_side;
	short	ray_horizontal_side;

	ray_horizontal_side = ((int)ray[Y] == ray[Y]) ? 1 : 0;
	ray_vertical_side = ((int)ray[X] == ray[X]) ? 1 : 0;
	if (ray_horizontal_side)
	{
		if (ray_dir[Y] >= 0)
			return (south);
		return (north);
	}
	else 
	{
		if (ray_dir[X] >= 0)
			return (west);
		return (east);
	}
}

static t_vect2i	get_coord_on_map(t_vect2d pos, t_vect2d ray_dir)
{
	t_vect2i	coord_on_map;

	// printf("pos_x: %f pos_y: %f\n", pos[X], pos[Y]);
	// printf("ray_dir_x: %f ray_dir_y: %f\n", ray_dir[X], ray_dir[Y]);

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
	{
		// printf("test1\n");
		offset_to_side[X] = fabs((int)(pos[X] + 1) - pos[X]);
	}
	else
	{
		// printf("test2\n");
		offset_to_side[X] = -1 * fabs(ceil(pos[X] - 1) - pos[X]);
	}
	if (dir[Y] > 0)
	{
		// printf("test3\n");
		offset_to_side[Y] = fabs((int)(pos[Y] + 1) - pos[Y]);
	}
	else
	{
		// printf("test4\n");
		offset_to_side[Y] = -1 * fabs(ceil(pos[Y] - 1) - pos[Y]);
	}
	// printf("o_x: %f o_y: %f\n", offset_to_side[X], offset_to_side[Y]);
	if (fabs(dir[Y] * offset_to_side[X]) < fabs(offset_to_side[Y] * dir[X]))
	{
		// printf("test5\n");
		step[X] = offset_to_side[X];
		step[Y] = step[X] * dir[Y] / dir[X];
	}
	else
	{
		step[Y] = offset_to_side[Y];
		step[X] = step[Y] * dir[X] / dir[Y];
	}
	
	// printf("step_x: %f step_y: %f\n", step[X], step[Y]);
	return (step);
}

#define FLOOR 0
#define SQ(x) ((x) * (x))
#define GET_DIST_BETWEEN(v1, v2) (sqrt(SQ(v1[X] - v2[X]) + SQ(v1[Y] - v2[Y])))

void			cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map *map, t_ray *ray)
{
	t_vect2i	coord_on_map;
	t_vect2d 	curr_pos;

	// f// printf(g_stream, "beg_pos_x: %f beg_pos_y: %f\n", pos[X], pos[Y]);
	// printf("beg_pos_x: %f beg_pos_y: %f\n", pos[X], pos[Y]);
	// printf("ray_x: %f ray_y: %f\n", ray_dir[X], ray_dir[Y]);
	coord_on_map[X] = (int)pos[X];
	coord_on_map[Y] = (int)pos[Y];
	curr_pos = pos;
	while (map->coord[coord_on_map[Y]][coord_on_map[X]] == FLOOR)
	{
		curr_pos += step_on_map(ray_dir, curr_pos);
		coord_on_map = get_coord_on_map(curr_pos, ray_dir);
		// f// printf(g_stream, "pos_x: %f pos_y: %f\n", curr_pos[X], curr_pos[Y]);
		// f// printf(g_stream, "i_pos_x: %d i_pos_y: %d\n", coord_on_map[X], coord_on_map[Y]);
	}
	ray->start_point = pos;
	ray->end_point = curr_pos;
	ray->dir = ray_dir;
	ray->end_on_map = coord_on_map;
	ray->value = map->coord[coord_on_map[Y]][coord_on_map[X]];
	ray->len = GET_DIST_BETWEEN(pos, curr_pos);
	ray->contact_side = determinate_side(ray_dir, curr_pos);
	// f// printf(g_stream, "value: %d len: %f\n", ray->value, ray->len);
}
