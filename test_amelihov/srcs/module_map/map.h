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

#include "../module_errors/errors.h"

#define SUCCESS 0
#define FAILURE 1

#define PATH_MAP "./resources/map"

typedef struct 	s_map
{
	int			**coord;
	int			w;
	int			h;
}				t_map;

short			init_map(t_map *map);
void			deinit_map(t_map *map);

#endif
