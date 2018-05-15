/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 14:19:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "game.h"
#include "player.h"

void	update(t_env *env)
{
	if (env->ui.is_acceleration)
		env->game.player.speed = ACCELERATION_SPEED;
	else if (env->ui.is_deceleration)
		env->game.player.speed = DECELERATION_SPEED;
	else
		env->game.player.speed = DEFAULT_SPEED;
	if (env->ui.motion)
		move_player(&env->game, env->ui.motion);
	if (env->ui.rotation)
		rotate_player(&env->game, env->ui.rotation);
}
