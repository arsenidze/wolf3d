/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../module_game/game.h"
#include "../module_graphics/graphics.h"
#include "../module_raycasting/raycasting.h"
#include "../module_wolf3d/wolf3d.h"
#include "../module_textures/textures.h"

#define MULL_VECT_ON_SCALAR(v, a) (v * (t_vect2d){a, a})
#define GET_RAY_DIR(x, d, p, w) (d + MULL_VECT_ON_SCALAR(p, x * 1. / w - 0.5))
#define X 0
#define Y 1
#define GET_LEN(v) (sqrt(v[X] * v[X] + v[Y] * v[Y]))
#define DOT_PROD(a, b) (a[X] * b[X] + a[Y] * b[Y])
#define COS_BETWEEN_VECTS(a, b) (DOT_PROD(a, b) / (GET_LEN(a) * GET_LEN(b)))

void 	draw_world(t_game *game, void *texs_arr, t_graphics *view)
{
	int			x;
	t_vect2d	ray_dir;
	t_hit		hit;
	t_texture	*texs;

	texs = (t_texture *)texs_arr;
	x = 0;
	while (x < WIN_W)
	{
		ray_dir = GET_RAY_DIR(x, game->player.dir, game->player.plane, WIN_W);
		cast_ray(ray_dir, game->player.pos, &game->map, &hit);
		hit->pendicular_dist = hit->ray_len *
		COS_BETWEEN_VECTS(ray_dir, game->player.dir);
		draw_wall(x, &hit, texs_arr, view);
		//draw_floor_and_ceil();
		x++;
	}
	mlx_put_image_to_window(view->mlx, view->win, view->img.ptr, 0, 0);
}
