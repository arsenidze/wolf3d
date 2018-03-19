/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_world_on_image_private.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_WORLD_ON_IMAGE_PRIVATE_H
# define PUT_WORLD_ON_IMAGE_PRIVATE_H

#include "game.h"
#include "graphics.h"
#include "raycasting.h"

/*
**	vslice - vertical slice
*/

typedef struct 	s_vslice
{
	int x;
	int	top;
	int bottom;
}				t_vslice;

/*
**	arguments for function - put_floor_and_ceil_on_img
*/

typedef struct 	s_pfac_arg
{
	t_vslice 	vslice;
	double 		curr_angle;
	t_ray		*ray;
	t_map 		*map;
	t_texture 	*texs;
	t_image 	*img;
}				t_pfac_arg;

void		put_world_on_image(t_game *game, t_texture texs[], t_image *img);

#define FLOOR_CEIL (-1)
t_texture	*match_tex(t_texture texs[], int value, int side);


#endif
