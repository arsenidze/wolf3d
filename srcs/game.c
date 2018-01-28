/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:24:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/28 15:12:18 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

#define INITIAL_POS (t_vect2d){22., 12.}
#define DEFAULT_DIR (t_vect2d){-1., 0.}
#define DEFAULT_PLANE (t_vect2d){0.0, 1.3}

void	init_game(t_game *game, int **map, int w, int h)
{
	game->map.coord = map;
	game->map.w = w;
	game->map.h = h;
	game->player.pos = INITIAL_POS;
	game->player.dir = DEFAULT_DIR;
	game->player.plane = DEFAULT_PLANE;
}
