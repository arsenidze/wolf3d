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

#include "../module_map/map.h"

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));
typedef int		t_vect2i __attribute__((vector_size(sizeof(int)*2)));

typedef enum 	e_side
{
	west,
	north,
	east,
	south
}				t_side;

typedef struct 	s_hit
{
	t_vect2d 	hit_point;
	t_vect2i 	pos_on_map;
	int 		value_on_map;
	double 		ray_len;
	double		perpendicular_dist;
	t_side		side;
}				t_hit;

void			cast_ray(t_vect2d ray_dir, t_vect2d pos, t_map *map,
				t_hit *hit);

#endif
