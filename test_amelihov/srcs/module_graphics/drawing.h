/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:59:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/08 10:03:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "../module_game/game.h"
#include "../module_raycasting/raycasting.h"
#include "../module_graphics/graphics.h"

void 	draw_world(t_game *game, void *texs_arr, t_graphics *view);
void 	draw_wall(int x, t_hit *hit, t_texture *texs_arr, t_graphics *view);
void 	draw_minimap(void);
void 	draw_player_info(void);