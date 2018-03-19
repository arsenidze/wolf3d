/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap_on_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
                                                                            
/* ************************************************************************** */

#include "put_minimap_on_image.h"
#include "vect2.h"

// #define PLAYER_SIZE 16

// static void put_player_on_minimap(int color, t_env *env)
// {
// 	t_vect2d 	pos;

// 	pos[X] = MINIMAP_X + env->game.player.pos[X] * PLAYER_SIZE;
// 	pos[Y] = MINIMAP_Y + env->game.player.pos[Y] * PLAYER_SIZE;
// 	SET_PIXEL(env->graphics.img, (int)pos[X], (int)pos[Y], color);
	
// }

// #define BOX_SIZE 16

// static void	put_box_on_image(int y, int x, int c, t_env *env)
// {
// 	int 	box_x;
// 	int 	box_y;
// 	int 	i;
// 	int		j;

// 	box_x = MINIMAP_X + x * (BOX_SIZE + BOX_SIZE / 4);
// 	box_y = MINIMAP_Y + y * (BOX_SIZE + BOX_SIZE / 4);
// 	j = 0;
// 	while (j < BOX_SIZE)
// 	{
// 		i = 0;
// 		while (i < BOX_SIZE)
// 		{
// 			SET_PIXEL(env->graphics.img, (box_x + i), (box_y + j), c);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	put_minimap_on_image(t_env *env)
// {
// 	int 	i;
// 	int 	j;
// 	int 	box_color;

// 	box_color = 0x00000000;
// 	j = 0;
// 	while (j < env->game.map.h)
// 	{
// 		i = 0;
// 		while (i < env->game.map.w)
// 		{
// 			if (env->game.map.coord[j][i])
// 			{
// 				put_box_on_image(j, i, box_color, env);
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	put_box_on_image(env->game.player.pos[X],
// 		env->game.player.pos[X], 0x00FF00FF, env);
// 	// put_player_on_minimap(0x00FF00FF, env);
// }

void	put_minimap_on_image(t_env *env)
{
	int 	minimap_w;
	int 	minimap_h;
	t_vect2d pos;
	int 	left;
	int 	top;

	minimap_w = WIN_W * 3 / 4;
	minimap_h = WIN_H * 3 / 4;
	pos = env->game.player.pos;
	left = pos[X] - minimap_w / 2;
	top = pos[Y] - minimap_h / 2;
	int i = left;
	// while (i < minimap_w / 2)
	// {
	// 	if (i < 0)
	// 		SET_PIXEL(env->graphics.img, 0x0000FFFF, (box_y + j), c);
	// }
}
