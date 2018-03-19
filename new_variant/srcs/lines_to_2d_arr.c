/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_to_2d_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 20:01:59 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_size(char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		i++;
	}
	return (i);
}

void		*free_map(int ***map)
{
	int		j;

	if (!*map)
		return (NULL);
	j = 0;
	while ((*map)[j])
	{
		free((*map)[j]);
		j++;
	}
	free(*map);
	*map = NULL;
	return (NULL);
}

int			**lines_to_2d_arr(char **lines, int *w, int *h)
{
	int		**map;
	int		j;
	int		i;
	int		nlines;
	int		line_len;

	nlines = get_size(lines);
	line_len = ft_strlen(lines[0]);
	if (!(map = malloc(sizeof(int *) * (nlines + 1))))
		return (NULL);
	map[nlines] = NULL;
	j = 0;
	while (j < nlines)
	{
		if (!(map[j] = malloc(sizeof(int) * line_len)))
			return (free_map(&map));
		i = 0;
		while (i < line_len)
		{
			map[j][i] = lines[j][i] - '0';
			i++;
		}
		j++;
	}
	*w = line_len;
	*h = nlines;
	return (map);
}

void 		free_lines(char ***lines)
{
	int 	i;

	i = 0;
	while ((*lines)[i])
	{
		free((*lines)[i]);
		i++;
	}
	free(*lines);
}