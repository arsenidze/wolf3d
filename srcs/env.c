/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 19:44:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

short	env_init(t_env *env)
{
	if (graphics_init(&env->graphics) != SUCCESS)
		return (FAILURE);
	if (textures_init(env->textures, &env->graphics) != SUCCESS)
		return (FAILURE);
	if (game_init(&env->game) != SUCCESS)
		return (FAILURE);
	reset_user_input(&env->ui);
	return (SUCCESS);
}

void	env_deinit(t_env *env)
{
	textures_deinit(env->textures, &env->graphics);
	graphics_deinit(&env->graphics);
	game_deinit(&env->game);
}
