/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "graphics.h"
#include "game.h"
#include "user_input.h"
#include "wolf3d_defines.h"

#define SUCCESS 0
#define FAILURE	1

typedef struct	s_env
{
	t_graphics 		graphics;
	t_game 			game;
	t_texture		textures[NTEXTURES];
	t_user_input 	ui;
}				t_env;

short 			env_init(t_env *env);
void 			env_deinit(t_env *env);
void			update(t_env *env);
void			render(t_env *env);
void 			run_event_handler_loop(t_env *env);

#endif
