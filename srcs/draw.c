/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:50:03 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 19:22:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"

#include <stdio.h>

#define SET_PIXEL(i, x, y, c) *(int *)(i.data + y * i.sl + x * i.bpp) = c
#define GET_COLOR(i, x, y) (*(int *)(i.data + y * i.sl + x * i.bpp / 8))

static void		copy_from_texture_to_img(t_image *img, t_range_in_img range,
				t_texture *tex, double pos_in_tex)
{
	int		y_iter;
	int 	x_in_tex;
	int 	y_in_tex;

	x_in_tex = (int)(pos_in_tex * (double)(tex->w - 1));
	y_iter = range.y_top;
	while (y_iter <= range.y_bottom)
	{
		y_in_tex = (float)(y_iter - range.y_top)
		/ (range.y_bottom - range.y_top) * (tex->h - 1);
		SET_PIXEL((*img), range.x, y_iter, 
		GET_COLOR(tex->img, (int)x_in_tex, y_in_tex));
		y_iter++;
	}
}

static void		put_line_to_img(t_image *img, t_range_in_img range, int color)
{
	int		y_iter;

	y_iter = range.y_top;
	while (y_iter <= range.y_bottom)
	{
		SET_PIXEL((*img), range.x, y_iter, color);
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

#define FLOOR 0

static t_vect2d	cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map map)
{
	t_vect2i	coord_on_map;

	coord_on_map[X] = (int)pos[X];
	coord_on_map[Y] = (int)pos[Y];
	while (map.coord[coord_on_map[Y]][coord_on_map[X]] == FLOOR)
	{
		pos += step_on_map(ray_dir, pos);
		coord_on_map = get_coord_on_map(pos, ray_dir);
	}
	return (pos);
}

#define MULL_VECT_ON_SCALAR(v, a) (v * (t_vect2d){a, a})
#define GET_RAY_DIR(x, d, p) (d + MULL_VECT_ON_SCALAR(p, x * 1. / WIN_W - 0.5)) 

void			draw(t_env *env)
{
	int			x;
	t_vect2d	ray_dir;
	t_vect2d	hit;

	ft_memset(env->img.data, 0, WIN_W * WIN_H * env->img.bpp);
	x = 0;
	while (x < WIN_W)
	{
		ray_dir = GET_RAY_DIR(x, env->game.player.dir, env->game.player.plane);
		hit = cast_ray(ray_dir, env->game.player.pos, env->game.map);
		copy_from_texture_to_img(&env->img,
						get_range_in_img(x, hit, ray_dir, &env->game.player),
						get_texture(hit, ray_dir, env->game.map.coord, env),
						get_x_in_texture(hit, ray_dir, env->game.map.coord));
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}
