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

#include "controllers.h"
#include "keys.h"
#include "env.h"
#include "user_input.h"
#include "game.h"
#include "mlx.h"
#include <stdlib.h>

#define I_DID_NOTHING 	0
#define I_DID_SOMETHING 1

int 	quit_contorller(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	env_deinit(env);
	exit(0);
	return (0);
}

int		keyboard_press_controller(int keycode, void *venv)
{
	t_env	*env;

	env = (t_env *)venv;
	if (keycode == BTN_ESC)
		quit_contorller(env);
	else if (keycode == BTN_TAB)
	{
		env->ui.is_minimap = !env->ui.is_minimap;
	}
	else if (keycode == BTN_W)
	{
		env->ui.motion |= MOTION_FORWARD;
	}
	else if (keycode == BTN_S)
	{
		env->ui.motion |= MOTION_BACKWARD;
	}
	else if (keycode == BTN_A)
	{
		env->ui.rotation |= ROTATION_LEFT;
	}
	else if (keycode == BTN_D)
	{
		env->ui.rotation |= ROTATION_RIGHT;
	}
	else 
		return (I_DID_NOTHING);
	// update(env);
	// render(env);
	return (I_DID_SOMETHING);
}

int		keyboard_release_controller(int keycode, void *venv)
{
	t_env	*env;

	env = (t_env *)venv;
	if (keycode == BTN_ESC)
		quit_contorller(env);
	else if (keycode == BTN_W)
	{
		env->ui.motion ^= MOTION_FORWARD;
	}
	else if (keycode == BTN_S)
	{
		env->ui.motion ^= MOTION_BACKWARD;
	}
	else if (keycode == BTN_A)
	{
		env->ui.rotation ^= ROTATION_LEFT;
	}
	else if (keycode == BTN_D)
	{
		env->ui.rotation ^= ROTATION_RIGHT;
	}
	else
		return (I_DID_NOTHING);
	// update(env);
	// render(env);
	return (I_DID_SOMETHING);
}

/*
**	16ms - 1 / 60 FPS
*/

#define MS_PER_FRAME 16

int 	idle_controller(t_env *env)
{
	update(env);
	render(env);
	return (0);
}

/*
** Event codes for mlx_hook
*/
#define KEY_PRESS 		2
#define KEY_RELEASE		3
#define DESTROY_NOTIFY	17


void	controllers_init(void *v_env)
{
	t_env	*env;

	env = (t_env *)v_env;
	mlx_do_key_autorepeatoff(env->graphics.mlx);
	mlx_hook(env->graphics.win, KEY_PRESS, 0, keyboard_press_controller, env);
	mlx_hook(env->graphics.win, KEY_RELEASE, 0, keyboard_release_controller, env);
	mlx_hook(env->graphics.win, DESTROY_NOTIFY, 0, quit_contorller, env);	
	mlx_loop_hook(env->graphics.mlx, idle_controller, env);
	reset_user_input(&env->ui);
}
