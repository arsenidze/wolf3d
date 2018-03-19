/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:11:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/09 18:11:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "map.h"
#include "vect2.h"

typedef enum 	e_side
{
	west,
	north,
	east,
	south
}				t_side;

typedef struct 	s_ray
{
	t_vect2d 	start_point;
	t_vect2d 	end_point;
	t_vect2d 	dir;
	double 		len;

	t_vect2i 	end_on_map;
	int 		value;
	t_side		contact_side;
}				t_ray;

void			cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map *map,
				t_ray *ray);

#endif
