/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/29 13:41:11 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINES_H
# define WOLF3D_DEFINES_H

/*
**	DON'T CHANGE WIN_W AND WIN_H!!!
*/
# define WIN_W 			1280
# define WIN_H 			1024
# define PROGNAME		"wolf3d"
# define PATH_MAP		"resources/map"
# define PATH_TEXS		"resources/textures/"
# define NTEXTURES 		12
# define WALL_HEIGHT	64
# define TILE_SIZE		64
# define PLAYER_HEIGHT	32
# define FOV			60
# define MINIMAP_W		(WIN_W / 4)
# define MINIMAP_H		(WIN_H / 4)
# define MINIMAP_X		10
# define MINIMAP_Y		10
# define HEALTH_BAR_H	140
# define HEALTH_BAR_W	1280
# define HEALTH_BAR_X	0
# define HEALTH_BAR_X	0
# define HEALTH_BAR_Y	(WIN_H - HEALTH_BAR_H)
# define WEAPON_H		(192)
# define WEAPON_X		(WIN_W / 2)
# define WEAPON_Y		(WIN_H - HEALTH_BAR_H - WEAPON_H + 4)

#endif
