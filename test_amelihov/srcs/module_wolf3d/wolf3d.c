/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:03:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/02 18:03:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "../module_graphics/graphics.h"

void	run_loop(t_env *env)
{
	printf("run_loop: %p\n", env->view.mlx);
	mlx_loop(env->view.mlx);
}

void	deinit_env(t_env *env)
{
	deinit_textures(env->textures, &env->view);
	deinit_graphics(&env->view);
	deinit_game(&env->game);
}