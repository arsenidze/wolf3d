/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_world_on_image_private.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 19:50:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_WORLD_ON_IMAGE_PRIVATE_H
# define PUT_WORLD_ON_IMAGE_PRIVATE_H

# include "game.h"
# include "graphics.h"
# include "raycasting.h"

/*
**	vslice - vertical slice
*/

typedef struct	s_vslice
{
	int		x;
	double	top;
	double	bottom;
}				t_vslice;

/*
**	arguments for function - put_floor_and_ceil_on_img
*/

typedef struct	s_pfac_arg
{
	t_vslice	vslice;
	double		curr_angle;
	t_ray		*ray;
	t_map		*map;
	t_texture	*texs;
	t_image		*img;
}				t_pfac_arg;

void			put_world_on_image(t_game *game, t_texture texs[],
				t_image *img);

# define FLOOR 			0
# define REDWALL		1
# define EAGLE			2
# define STONE			3
# define AXIDSTONE		4
# define PURPLESTONE	5
# define CEIL  			6
# define DIFF_SIDES		7

t_texture		*match_tex(t_texture texs[], int value, int side);

#endif
