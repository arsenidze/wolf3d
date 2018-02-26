/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:24:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 17:19:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

#define INITIAL_POS (t_vect2d){1.5, 1.5}
#define DEFAULT_DIR (t_vect2d){0., 1.}
#define DEFAULT_PLANE (t_vect2d){1.3, 0.0}

void	init_game(t_game *game, int **map, int w, int h)
{
	game->map.coord = map;
	game->map.w = w;
	game->map.h = h;
	game->map.coord[1][1] = 0;
	game->player.pos = INITIAL_POS;
	game->player.dir = DEFAULT_DIR;
	game->player.plane = DEFAULT_PLANE;
	game->player.colider_radius = 0.5;
}
