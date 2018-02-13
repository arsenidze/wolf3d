/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:11:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/13 18:11:56 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

double			get_x_in_texture(t_vect2d hit, t_vect2d dir, int **map)
{
	short		hit_vertical_side;
	short		hit_horizontal_side;

	hit_horizontal_side = ((int)hit[Y] == hit[Y]) ? 1 : 0;
	hit_vertical_side = ((int)hit[X] == hit[X]) ? 1 : 0;
	if (hit_vertical_side && hit_horizontal_side)
	{
		if (dir[X] == 0)
			return (hit[X] - floor(hit[X]));
		if (dir[Y] == 0)
			return (ceil(hit[Y]) - hit[Y]);
		return (hit[X] - floor(hit[X]));
	}
	else if (hit_vertical_side)
		return (ceil(hit[Y]) - hit[Y]);
	else
		return (hit[X] - floor(hit[X]));
}

#define SQ(x) ((x) * (x))
#define GET_DIST_BETWEEN(v1, v2) (sqrt(SQ(v1[X] - v2[X]) + SQ(v1[Y] - v2[Y])))
#define WALL_HEIGHT (WIN_W)

t_range_in_img	get_range_in_img(int x, t_vect2d hit, t_vect2d pos)
{
	float			ray_len;
	t_range_in_img 	range;

	ray_len = GET_DIST_BETWEEN(hit, pos);
	range.y_top = WIN_H / 2 - WALL_HEIGHT / ray_len;
		range.y_bottom = WIN_H / 2 + WALL_HEIGHT / ray_len;
		if (range.y_top < 0)
			range.y_top = 0;
		if (range.y_bottom > WIN_H - 1)
			range.y_bottom = WIN_H - 1;
	range.x = x;
	return (range);
}

t_vect2i		get_coord_on_map(t_vect2d pos, t_vect2d ray_dir)
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