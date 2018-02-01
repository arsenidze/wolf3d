/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:41:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/31 17:56:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keys.h"
#include <stdlib.h>
#include <math.h>

#define DIR_STEP 0.5
#define ROTATE_ANGLE 4.0 * M_PI / 180.0

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
/*
int		loop_hook(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	(void)env;
//	draw(env);
	return (0);
}
*/
int		exit_hook(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	del(env);
	exit(0);
	return (0);
}
