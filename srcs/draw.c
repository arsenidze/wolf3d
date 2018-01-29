/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:50:03 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/29 22:48:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"

#include <stdio.h>
/*
static int		get_color(int n)
{
	if (n == 1)
		return (0xFF0000);
	if (n == 2)
		return (0x00FF00);
	if (n == 3)
		return (0x0000FF);
	if (n == 4)
		return (0xFFFFFF);
	return (0x00FFFF);
}
*/

#define SQ(x) ((x) * (x))

/*
static double	cast_ray(t_vect2d pos, t_vect2d ray, t_map *game_map, short *side,
				int *color)
{
	double		side_dist[2];
	double		delta_dist[2];
	int			map[2];
	int			step[2];

	map[X] = (int)pos[X];
	map[Y] = (int)pos[Y];
	delta_dist[X] = sqrt(SQ(ray[X]) + SQ(ray[Y])) / ray[X];
	delta_dist[Y] = sqrt(SQ(ray[Y]) + SQ(ray[Y])) / ray[Y];
	if (ray[X] < 0)
	{
		step[X] = -1;
		side_dist[X] = (pos[X] - map[X]) * delta_dist[X];
	}
	else
	{
		step[X] = 1;
		side_dist[X] = (map[X] + 1 - pos[X]) * delta_dist[X];
	}
	if (ray[Y] < 0)
	{
		step[Y] = -1;
		side_dist[Y] = (pos[Y] - map[Y]) * delta_dist[Y];
	}
	else
	{
		step[Y] = 1;
		side_dist[Y] = (map[Y] + 1 - pos[Y]) * delta_dist[Y];
	}
	while (game_map->data[map[X]][map[Y]] == 0)
	{
		if (side_dist[X] < side_dist[Y])
		{
			side_dist[X] += delta_dist[X];
			map[X] += step[X];
			*side = 0;
		}
		else
		{
			side_dist[Y] += delta_dist[Y];
			map[Y] += step[Y];
			*side = 1;
		}
	}
	*color = get_color(game_map->data[map[X]][map[Y]]);
	if (*side == 1)
		*color /= 2;
	if (*side == 0)
		return ((map[X] - pos[X] + (1 - step[X]) / 2) / ray[X]);
	return ((map[Y] - pos[Y] + (1 - step[Y]) / 2) / ray[Y]);

}
*/
//#define SET_PIXEL(i, x, y, c) *(int *)(i->data + y * i->sl + x * i->bpp) = c

#define START 0
#define END 1
/*
static void		put_line_to_img(t_image *img, int x, int draw[2], int color)
{
	int		y;

	y = draw[START];
	while (y <= draw[END])
	{
		SET_PIXEL(img, x, y, color);
		y++;
	}
}
*/
/*
void			draw(t_env *env)
{
	t_game		*game;
	t_vect2d	ray;
	double		dist_to_wall;
	int			x;
	short		side;
	int			line_height;
	int			color;
	int			draw[2];

	game = &env->game;
	x = 0;
	while (x < WIN_W)
	{
		ray = game->player.dir + game->player.plane *
		(t_vect2d){x / WIN_W - 0.5, x / WIN_W - 0.5};
		dist_to_wall = cast_ray(game->player.pos, ray, &game->map, &side, &color);
		line_height = (int)(WIN_H / dist_to_wall);
		draw[START] = -line_height / 2 + WIN_H / 2;
		if (draw[START] < 0)
			draw[START] = 0;
		draw[END] = line_height / 2 + WIN_H / 2;
		if (draw[END] >= WIN_H)
			draw[END] = WIN_H - 1;
		put_line_to_img(&env->img, x, draw, color);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}
*/

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

static double	dist_between(t_vect2d v1, t_vect2d v2)
{
	return (sqrt(SQ(v1[X] - v2[X]) + SQ(v1[Y] - v2[Y])));
}

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SIGN(x) ((x) < 0 ? -1 : ((x) != 0))

static t_vect2d	step(t_vect2d ray, t_vect2d pos)
{
	t_vect2d	offset_to_side;
	t_vect2d	step;


	if (ray[X] > 0)
		offset_to_side[X] = ((int)fabs(pos[X]) + 1 - fabs(pos[X]));
	else
		offset_to_side[X] = -1 * (fabs(pos[X]) - (int)fabs(pos[X]));
	if (ray[Y] > 0)
		offset_to_side[Y] = ((int)fabs(pos[Y]) + 1 - fabs(pos[Y]));
	else
		offset_to_side[Y] = -1 * (fabs(pos[Y]) - (int)fabs(pos[Y]));
	printf("offset: %f %f\n", offset_to_side[X], offset_to_side[Y]);
	sleep(2);
	if (fabs(ray[Y] * offset_to_side[X]) < fabs(offset_to_side[Y] * ray[X]))
	{
		step[X] = offset_to_side[X];
		step[Y] = step[X] * ray[Y] / ray[X];
	}
	else
	{
		step[Y] = offset_to_side[Y];
		step[X] = step[Y] * ray[X] / ray[Y];
	}
	printf("step: %f %f\n", step[X], step[Y]);
	sleep(2);
	return (step);
}

static t_vect2d	cast_ray(t_vect2d ray, t_vect2d pos, t_map map)
{
	printf("pos0: %f %f\n", pos[X], pos[Y]);
	sleep(2);
	while (map.coord[(int)pos[X]][(int)pos[Y]] == 0)
	{
		pos += step(ray, pos);
	}
	printf("pos: %f %f\n", pos[X], pos[Y]);
	return ((t_vect2d){pos[X], pos[Y]});
}

#define LINE_HEIGHT WIN_H

void			draw(t_env *env)
{
	int			x;
	t_vect2d	ray;
	t_vect2d	hit;
	int			y[2];
	double		dist;

	ft_memset(env->img.data, 0, WIN_W * WIN_H * env->img.bpp);
	x = 0;
	while (x < WIN_W)
	{
		printf("x: %d\n", x);
		ray = env->game.player.dir + env->game.player.plane *
		(t_vect2d){x * 1. / WIN_W - 0.5, x * 1. / WIN_W - 0.5};
		printf("+_%f %f\n", ray[X], ray[Y]);
		hit = cast_ray(ray, env->game.player.pos, env->game.map);
		dist = dist_between(env->game.player.pos, hit);
		y[0] = WIN_H / 2 - LINE_HEIGHT / dist;
		y[1] = WIN_H / 2 + LINE_HEIGHT / dist;
		y[0] = (y[0] < 0) ? 0 : y[0];
		y[1] = (y[1] > WIN_H - 1) ? WIN_W - 1 : y[1];
		put_line_to_img(env, x, y, get_color(hit[X], hit[Y],
		env->game.map.coord));
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr, 0, 0);
}
