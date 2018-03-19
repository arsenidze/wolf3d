/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:03:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/02 18:03:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include "../module_game/game.h"
#include "../module_graphics/graphics.h"
#include "../module_userinput/userinput.h"
#include "../module_textures/textures.h"

#define WIN_W 		800
#define WIN_H 		800
#define SUCCESS 	0
#define FAILURE 	1
#define PROGNAME	"wolf3d"

typedef struct 	s_env
{
	t_game			game;
	t_userinput 	ui;
	t_graphics		view;
	t_texture		textures[NTEXTURES];
} 				t_env;

void			run_loop(t_env *env);
void			deinit_env(t_env *env);

#endif
