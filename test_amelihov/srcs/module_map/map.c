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

#include "map.h"
#include "../../lib/libft/includes/libft.h"
#include "is_valid.h"
#include "lines_to_2d_arr.h"
#include "fcntl.h"

static void		init_map_failure(t_map *map, char *err)
{
	deinit_map(map);
	try_set_err(err);
}

short			init_map(t_map *map)
{
	char	**lines;

	map->coord = NULL;
	if (!(lines = read_file(PATH_MAP)))
	{
		init_map_failure(map, FILE_READING_FAILURE);
		return (FAILURE);
	}
	if (!is_valid(lines))
	{
		init_map_failure(map, FILE_VALIDATION_FAILURE);
		return (FAILURE);
	}
	if (!(map->coord = lines_to_2d_arr(lines, &map->w, &map->h)))
	{
		init_map_failure(map, MEMORY_FAILURE);
		return (FAILURE);
	}
	return (SUCCESS);
}

void			deinit_map(t_map *map)
{
	free(map->coord);
}