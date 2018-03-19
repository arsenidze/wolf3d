/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 20:01:59 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#define SUCCESS 0
#define FAILURE	1

typedef struct 	s_map
{
	int			**coord;
	int			w;
	int			h;
}				t_map;

short			map_init(t_map *map);
void			map_deinit(t_map *map);

#endif
