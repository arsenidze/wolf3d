/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../module_game/game.h"
#include "../module_graphics/graphics.h"
#include "drawing.h"

void	render(t_game *game, void *texs_arr, t_graphics *view);
{
	draw_world(game, texs_arr, view);
	draw_minimap();
	draw_player_info();
}