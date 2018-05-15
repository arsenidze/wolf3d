/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap_on_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:47:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:49:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_minimap_on_image.h"
#include "wolf3d_defines.h"
#include "vect2.h"

#define WIDTH 	0
#define HEIGHT 	1

static void	put_box_on_minimap(int x, int y, int color, t_env *env)
{
	int		i;
	int		j;
	int		x_on_img;
	int		y_on_img;
	int		box_scales[2];

	box_scales[WIDTH] = MINIMAP_W / env->game.map.w;
	box_scales[HEIGHT] = MINIMAP_H / env->game.map.h;
	x_on_img = MINIMAP_X + x * box_scales[WIDTH];
	y_on_img = MINIMAP_Y + y * box_scales[HEIGHT];
	j = 0;
	while (j < box_scales[HEIGHT])
	{
		i = 0;
		while (i < box_scales[WIDTH])
		{
			SET_PIXEL((env->graphics.img), x_on_img + i, y_on_img + j, color);
			i++;
		}
		j++;
	}
}

#define IN_MAP(i, j, m) (((i) >= 0 && (i) < m.w) && ((j) >= 0 && (j) < m.h))
#define CHOOSE_COLOR(value) ((value) ? 0x000000 : 0x00FFFFFF)

void		put_minimap_on_image(t_env *env)
{
	int		left;
	int		top;
	int		i;
	int		j;
	int		color;

	left = 0;
	top = 0;
	j = 0;
	while (j < env->game.map.h)
	{
		i = 0;
		while (i < env->game.map.w)
		{
			if (IN_MAP(i, j, env->game.map))
				color = CHOOSE_COLOR(env->game.map.coord[j][i]);
			else
				color = 0x00808080;
			put_box_on_minimap(i, j, color, env);
			i++;
		}
		j++;
	}
	put_box_on_minimap((int)env->game.player.pos[X],
		(int)env->game.player.pos[Y], 0x00FF0000, env);
}
