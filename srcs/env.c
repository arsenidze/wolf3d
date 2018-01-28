/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:40 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/28 17:52:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <stddef.h>

void	del(t_env *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img.ptr)
		mlx_destroy_image(env->mlx, env->img.ptr);
	if (env->game.map.coord)
		free_map(&env->game.map.coord);
}

short	init(t_env *env, int **map, int w, int h)
{
	env->game.map.coord = NULL;
	if (!(env->mlx = mlx_init()))
	{
		del(env);
		return (1);
	}
	if (!(env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "wolf3d")))
	{
		del(env);
		return (2);
	}
	if (!(env->img.ptr = mlx_new_image(env->mlx, WIN_W, WIN_H)))
	{
		del(env);
		return (3);
	}
	env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
	&env->img.sl, &env->img.endian);
	env->img.bpp /= 8;
	init_game(&env->game, map, w, h);
	return (SUCCESS);
}
