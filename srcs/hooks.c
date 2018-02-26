/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:41:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/22 19:29:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keys.h"
#include <stdlib.h>
#include <math.h>

#define MOTION_FORWARD 	0b00000001
#define MOTION_BACKWARD	0b00000010
#define ROTATION_LEFT  	0b00000001
#define ROTATION_RIGHT 	0b00000010

/*
int		key_press_hook(int keycode, void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	if (keycode == BTN_ESC)
		exit_hook(env);
	else if (keycode == BTN_W)
	{
		move(&env->game.player, &env->game.map, DIR_STEP);
	}
	else if (keycode == BTN_S)
	{
		move(&env->game.player, &env->game.map, -DIR_STEP);
	}
	else if (keycode == BTN_A)
	{
		rotate(&env->game.player, &env->game.map, ROTATE_ANGLE);
	}
	else if (keycode == BTN_D)
	{	
		rotate(&env->game.player, &env->game.map, -ROTATE_ANGLE);
	}
	draw(env);
	return (0);
}
*/

int		key_press_hook(int keycode, void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	if (keycode == BTN_ESC)
		exit_hook(env);
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
	if (env->ui.motion)
	{
		move(&env->game.player, &env->game.map, env->ui.motion);
		draw(env);
	}
	if (env->ui.rotation)
	{
		rotate(&env->game.player, &env->game.map, env->ui.rotation);
		draw(env);
	}
	return (0);
}

int		key_release_hook(int keycode, void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	if (keycode == BTN_W)
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
	if (env->ui.motion)
	{
		move(&env->game.player, &env->game.map, env->ui.motion);
		draw(env);
	}
	if (env->ui.rotation)
	{
		rotate(&env->game.player, &env->game.map, env->ui.rotation);
		draw(env);
	}
	return (0);
}


int		loop_hook(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	(void)env;
//	draw(env);
/*
	if (env->ui.motion)
	{
		move(&env->game.player, &env->game.map, env->ui.motion);
		draw(env);
	}
	if (env->ui.rotation)
	{
		rotate(&env->game.player, &env->game.map, env->ui.rotation);
		draw(env);
	}
*/
	return (0);
}

int		exit_hook(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	deinit_env(env);
	exit(0);
	return (0);
}
