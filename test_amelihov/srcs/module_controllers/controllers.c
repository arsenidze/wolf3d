/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:10:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 10:10:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../module_wolf3d/wolf3d.h"
#include "keys.h"
#include "../module_game/game.h"
#include "../module_graphics/graphics.h"
#include "../module_userinput/userinput.h"
#include <stdlib.h>

#define I_DID_NOTHING 	0
#define I_DID_SOMETHING 1

int 	quit_contorller(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	deinit_env(env);
	exit(0);
	return (0);
}

int		keyboard_press_controller(int keycode, void *venv)
{
	t_env	*env;

	env = (t_env *)venv;
	if (keycode == BTN_ESC)
		quit_contorller(env);
	else if (keycode == BTN_SPACE)
	{
		render(&env->game, env->textures, &env->view);
		return (I_DID_SOMETHING);
	}
	else
		return (I_DID_NOTHING);
	update(&env->game, &env->ui);
	render(&env->game, env->textures, &env->view);
	return (I_DID_SOMETHING);
}

int		keyboard_release_controller(int keycode, void *venv)
{
	t_env	*env;

	env = (t_env *)venv;
	if (keycode == BTN_ESC)
		quit_contorller(env);
	else
		return (I_DID_NOTHING);
	update(&env->game, &env->ui);
	render(&env->game, env->textures, &env->view);
	return (I_DID_SOMETHING);
}

/*
** Event codes for mlx_hook
*/
#define KEY_PRESS 		2
#define KEY_RELEASE		3
#define DESTROY_NOTIFY	17

void	init_controllers(void *v_env)
{
	t_env	*env;

	env = (t_env *)venv;
	mlx_hook(env->view.win, KEY_PRESS, 0, keyboard_press_controller, env);
	mlx_hook(env->view.win, KEY_RELEASE, 0, keyboard_release_controller, env);
	mlx_hook(env->view.win, DESTROY_NOTIFY, 0, quit_contorller, env);	
	reset_userinput(&env->ui);
}