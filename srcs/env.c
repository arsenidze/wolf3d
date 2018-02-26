/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:40 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/22 17:35:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <stddef.h>

void	deinit_env(t_env *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img.ptr)
		mlx_destroy_image(env->mlx, env->img.ptr);
	if (env->game.map.coord)
		free_map(&env->game.map.coord);
	deinit_textures(env);
}

short	init_env(t_env *env, int **map, int w, int h)
{
	env->game.map.coord = NULL;
	env->texs[0].img.ptr = NULL;
	if (!(env->mlx = mlx_init()))
	{
		deinit_env(env);
		return (1);
	}
	if (!(env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "wolf3d")))
	{
		deinit_env(env);
		return (2);
	}
	if (!(env->img.ptr = mlx_new_image(env->mlx, WIN_W, WIN_H)))
	{
		deinit_env(env);
		return (3);
	}
	env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
	&env->img.sl, &env->img.endian);
	env->img.bpp /= 8;
	if (init_textures(env) != SUCCESS)
	{
		deinit_env(env);
		return (4);
	}
	init_game(&env->game, map, w, h);
	reset_user_input(&env->ui);
	return (SUCCESS);
}
