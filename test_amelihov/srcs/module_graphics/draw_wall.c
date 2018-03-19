/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../module_raycasting/raycasting.h"
#include "../module_graphics/graphics.h"
#include "../module_textures/textures.h"
#include "../module_wolf3d/wolf3d.h"
#include <math.h>

double			get_x1_in_texture(t_vect2d hit, t_vect2d dir, int **map)
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

static double 	get_x_in_texture(t_hit *hit)
{
	if (hit->size == west || hit->side == east)
		return (ceil(hit[Y]) - hit[Y]);
	return (hit[X] - floor(hit[X]));
}

/*
**	0.86  - tg(30deg)
**	30deg - half of FOV
*/
#define DIST_TO_PJ (WIN_W * 0.86)

#define SET_PIXEL(i, x, y, c) *(int *)(i.data + y * i.sl + x * i.bpp) = c
#define GET_COLOR(i, x, y) (*(int *)(i.data + y * i.sl + x * i.bpp))

void 			draw_wall(int x, t_hit *hit, t_textures texs[], t_graphics *view)
{
	t_texture 	*tex;
	double 		tex_x;
	int 		tex_y;
	int			wall_pj_height;
	int 		wall_pj_top;
	int 		wall_pj_bottom;
	int 		i;

	tex = match_texture(hit->value_on_map, hit->side, texs);
	tex_x = get_x_in_texture(hit);
	wall_pj_height = DIST_TO_PJ * tex->h / hit->perdicular_dist;
	wall_pj_bottom = WIN_H / 2 + wall_pj_height / 2;
	wall_pj_top = WIN_H / 2 - wall_pj_height / 2;
	i = wall_pj_top;
	while (i <= wall_bottom)
	{
		tex_y = (float)(i - wall_pj_top) / (wall_pj_bottom - wall_pj_top) *
		(tex->h - 1);
		SET_PIXEL(view->img, x, i, GET_COLOR(tex->img, (int)tex_x, tex_y));
		i++;
	}
}
