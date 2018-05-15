/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 20:01:59 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d_defines.h"
#include "map.h"
#include "libft.h"
#include "errors.h"
#include "map_private.h"
#include <stdlib.h>

static void		map_init_failure(t_map *map, char *err)
{
	map_deinit(map);
	try_set_err(err);
}

short			map_init(t_map *map)
{
	char	**lines;

	map->coord = NULL;
	if (!(lines = read_file(PATH_MAP)))
	{
		map_init_failure(map, FILE_READING_FAILURE);
		return (FAILURE);
	}
	if (!is_valid(lines))
	{
		map_init_failure(map, FILE_VALIDATION_FAILURE);
		return (FAILURE);
	}
	if (!(map->coord = lines_to_2d_arr(lines, &map->w, &map->h)))
	{
		map_init_failure(map, MEMORY_FAILURE);
		return (FAILURE);
	}
	free_lines(&lines);
	return (SUCCESS);
}

void			map_deinit(t_map *map)
{
	free_map(&map->coord);
}
