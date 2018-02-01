/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:50:03 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/01 21:25:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"

#include <stdio.h>

#define SET_PIXEL(i, x, y, c) *(int *)(i.data + (y * WIN_W + x) * i.bpp) = c

static void		put_line_to_img(t_env *env, int x, int y[2], int color)
{
	int		y_iter;

	y_iter = y[0];
	while (y_iter <= y[1])
	{
		SET_PIXEL(env->img, x, y_iter, color);
		y_iter++;
	}
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

#define GET_DIST_BETWEEN(v1, v2) (sqrt(SQ(v1[X] - v2[X]) + SQ(v1[Y] - v2[Y])))
#define SQ(x) ((x) * (x))
#define FLOOR 0
#define WALL !FLOOR

static double	cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map map, int hit[2])
{
	t_vect2d	beg_pos;
	int			coord_on_map[2];

	beg_pos = pos;
	coord_on_map[X] = (int)pos[X];
	coord_on_map[Y] = (int)pos[Y];
	while (map.coord[coord_on_map[X]][coord_on_map[Y]] == FLOOR)
	{
		pos += step_on_map(ray_dir, pos);
		if ((pos[X] == (int)pos[X]) && ray_dir[X] < 0)
			coord_on_map[X] = (int)pos[X] - 1;
		else
			coord_on_map[X] = (int)pos[X];
		if ((pos[Y] == (int)pos[Y]) && ray_dir[Y] < 0)
			coord_on_map[Y] = (int)pos[Y] - 1;
		else
			coord_on_map[Y] = (int)pos[Y];
	}
	hit[X] = coord_on_map[X];
	hit[Y] = coord_on_map[Y];
	return (GET_DIST_BETWEEN(beg_pos, pos));
}

#define WALL_HEIGHT WIN_H

void			draw(t_env *env)
{
	int			x;
	t_vect2d	ray_dir;
	int			hit[2];
	double		ray_len;
	int			y[2];

	ft_memset(env->img.data, 0, WIN_W * WIN_H * env->img.bpp);
	x = 0;
	while (x < WIN_W)
	{
		ray_dir = env->game.player.dir + env->game.player.plane *
		(t_vect2d){x * 1. / WIN_W - 0.5, x * 1. / WIN_W - 0.5};
		ray_len = cast_ray(ray_dir, env->game.player.pos, env->game.map, hit);
		y[0] = WIN_H / 2 - WALL_HEIGHT / ray_len;
		y[1] = WIN_H / 2 + WALL_HEIGHT / ray_len;
		if (y[0] < 0)
			y[0] = 0;
		if (y[1] > WIN_H - 1)
			y[1] = WIN_H - 1;
		put_line_to_img(env, x, y, match_color(hit[X], hit[Y],
		env->game.map.coord));
		x++;
	}
	printf("dir_x: %f dir_y: %f\n", env->game.player.dir[X],
									env->game.player.dir[Y]);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}
