/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_world_on_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "put_world_on_image_private.h"
#include "raycasting.h"
#include "graphics.h"
#include "vect2.h"
#include "wolf3d_defines.h"
#include <math.h>

typedef struct 	s_pfac_arg
{
	t_vslice 	vslice;
	double 		curr_angle;
	t_ray		*ray;
	t_map 		*map;
	t_texture 	*texs;
	t_image 	*img;
}				t_pfac_arg;

/*
**	0.86602540378  - 1 / (2 * tg(30deg))
**	30deg          - half of FOV
*/
#define DIST_TO_PJ (WIN_W * 0.86602540378)

static void		put_floor_and_ceil(t_pfac_arg  *arg)
{
	int 		y;
	t_vect2d 	tmp;
	double 		curr_dist;
	t_texture 	*tex;
	t_vect2d	pos_in_tex;

	y = arg->vslice.bottom;
	while (y < WIN_H)
	{
		curr_dist = (double)PLAYER_HEIGHT / (y - WIN_H / 2) *
		(double)DIST_TO_PJ / cos(arg->curr_angle) / (TILE_SIZE);
 		tmp = VECT2_MULL_ON_SCALAR(VECT2_NORM(arg->ray->dir), curr_dist) +
 			arg->ray->start_point;
 		tex = match_tex(arg->texs,
 			arg->map->coord[(int)tmp[Y]][(int)tmp[X]], arg->ray->contact_side);
 		pos_in_tex[X] = tmp[X] - (int)tmp[X];
 		pos_in_tex[Y] = tmp[Y] - (int)tmp[Y];
 		pos_in_tex[X] *= (double)(tex->w - 1);
 		pos_in_tex[Y] *= (double)(tex->h - 1);
 		SET_PIXEL((*(arg->img)), arg->vslice.x, y,
 			GET_PIXEL(tex->img, (int)pos_in_tex[X], (int)pos_in_tex[Y]));
 		SET_PIXEL((*(arg->img)), arg->vslice.x, (WIN_H - y),
 			GET_PIXEL(tex->img, (int)pos_in_tex[X], (int)pos_in_tex[Y]));
		y++;
	}
}


// static void		put_floor_and_ceil(t_vslice vslice, t_vect2d ray_dir, t_ray *ray,
// 				t_map *map, double dist, double curr_angle, t_texture texs[], t_image *img)
// {
// 	int 		y;
// 	t_vect2d	normalize;
// 	t_vect2d 	tmp;
// 	double 		curr_dist;
// 	double 		curr_dist1;
// 	double 		curr_dist2;
// 	int 		y1;

// 	double 		begin_angle = atan((TILE_SIZE * dist) / PLAYER_HEIGHT);
// 	double 		end_angle = atan(2 * DIST_TO_PJ / WIN_H);
// 	double 		delta_angle = (begin_angle - end_angle) / (WIN_H - vslice.bottom);
// 	double 		iter_angle = begin_angle;

// 	// iter_angle -= delta_angle;

// 	normalize = DIV_VECT_ON_SCALAR(ray_dir, GET_LEN(ray_dir));
// 	y = vslice.bottom;
// 	y1 = vslice.top;
// 	while (y < WIN_H)
// 	{
// 		// curr_dist1 = (double)(y - vslice.bottom) / (double)(WIN_H - vslice.bottom) *
// 		// ((double)DIST_TO_PJ / WIN_H - dist) + dist;

// 		curr_dist1 =  DIST_TO_PJ * (double)(PLAYER_HEIGHT / (double)(DIST_TO_PJ / (2 * dist) + (y - vslice.bottom))) / cos(curr_angle) / (TILE_SIZE);
// 		curr_dist2 = (double)(tan(iter_angle) * PLAYER_HEIGHT) / TILE_SIZE;
// 		curr_dist = (double)PLAYER_HEIGHT / (y - WIN_H / 2) * (double)DIST_TO_PJ / cos(curr_angle) / (TILE_SIZE);

// 		printf("d: %f dc1: %f d2: %f tmp: %f\n", curr_dist, curr_dist1, curr_dist2, dist / cos(curr_angle));
// 		sleep(1);


//  		tmp = MULL_VECT_ON_SCALAR(normalize, curr_dist) + ray->start_point;

//  		t_texture 	*tex = match_tex(texs, map->coord[(int)tmp[Y]][(int)tmp[X]], ray->side);

//  		double 		x_tex = tmp[X] - (int)tmp[X];
//  		double 		y_tex = tmp[Y] - (int)tmp[Y];


//  		// if (ray->value == 3)
//  		// {
//  		// 	printf("----t_w: %d t_h: %d %p\n", tex->w, tex->h, tex);
//  		// 	printf("r_x: %f r_y: %f\n", tmp[X], tmp[Y]);
//  		// 	printf("x_tex: %f y_tex: %f\n", x_tex, y_tex);
//  		// }

//  		x_tex *= (double)(tex->w - 1);
//  		y_tex *= (double)(tex->h - 1);

//  		// if (ray->value == 3)
//  		// 	printf("+++x_tex: %f y_tex: %f\n", x_tex, y_tex);


//  		SET_PIXEL((*img), vslice.x, y, GET_PIXEL(tex->img, (int)x_tex, (int)y_tex));
//  		SET_PIXEL((*img), vslice.x, y1, GET_PIXEL(tex->img, (int)x_tex, (int)y_tex));
//  		iter_angle -= delta_angle;
// 		y++;
// 		y1--;
// 	}
// }

static double	x_in_tex(t_ray *ray)
{
	if (ray->contact_side == west || ray->contact_side == east)
		return (ceil(ray->end_point[Y]) - ray->end_point[Y]);
	return (ray->end_point[X] - floor(ray->end_point[X]));
}

static void	put_wall_on_img(t_vslice vslice, double pos_in_tex,
			t_texture *tex, t_image *img)
{
	int 	y;
	int 	x_tex;
	int 	y_tex;

	x_tex = pos_in_tex * (tex->w - 1);
	y = vslice.top;
	while (y <= vslice.bottom)
	{
		y_tex = (tex->h - 1) * (float)(y - vslice.top) / (vslice.bottom - vslice.top);
		if (!(y < 0 || y >= WIN_H))
			SET_PIXEL((*img), vslice.x, y, GET_PIXEL(tex->img, x_tex, y_tex));
		y++;
	}
}

// #define GET_RAY_DIR(x, d, p, w) (d + MULL_VECT_ON_SCALAR(p, x * 1. / w - 0.5))

static t_vslice 	get_slice_range(int x, double len, double angle)
{
	t_vslice 	vslice;
	double 		perpendicular_dist;
	int 		wall_pj_height;

	perpendicular_dist = len * cos(angle);
	wall_pj_height = DIST_TO_PJ / perpendicular_dist;
	vslice.x = x;
	vslice.top = WIN_H / 2 - wall_pj_height / 2;
	vslice.bottom = WIN_H / 2 + wall_pj_height / 2;
	return (vslice);
}

#define DEG_TO_RAD(deg) (double)((deg) * M_PI / 180.0)
#define RAD_TO_DEG(rad) (double)((rad) * 180.0 / M_PI)

#define START_ANGLE DEG_TO_RAD(-FOV / 2)
#define DELTA_ANGLE (double)(DEG_TO_RAD(FOV) / WIN_W)

void	put_world_on_image(t_game *game, t_texture texs[], t_image *img)
{
	int			x;
	double 		curr_angle;
	t_vect2d	ray_dir;
	t_ray		ray;
	t_vslice	vslice;

	curr_angle = START_ANGLE;
	x = 0;
	while (x < WIN_W)
	{
		ray_dir = VECT2_ROTATE(game->player.dir, curr_angle);
		cast_ray(ray_dir, game->player.pos, &game->map, &ray);
		vslice = get_slice_range(x, ray.len, curr_angle);
		put_wall_on_img(vslice, x_in_tex(&ray),
			match_tex(texs, ray.value, ray.contact_side), img);
		// put_floor_ceil(vslice, &ray, &game->map,
		// curr_angle, texs, img);
		put_floor_and_ceil(&(t_pfac_arg){vslice, curr_angle, &ray, &game->map,
			texs, img});
		// t_put_floor_ceil_arg 	pfc_arg;
		// pfc_arg.ray = &ray;
		// pfc_arg.map = map;
		// pfc_arg.ray = ray;

		// put_floor_ceil(pfc_arg);
		curr_angle += DELTA_ANGLE;
		x++;
	}
}
