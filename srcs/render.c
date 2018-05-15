/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:43:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "put_world_on_image_private.h"
#include "put_minimap_on_image.h"
#include "get_next_weapon_animation_index.h"
#include "graphics.h"
#include "wolf3d_defines.h"
#include "libft.h"
#include "mlx.h"

void	render(t_env *env)
{
	int		weapon_animation_index;

	ft_memset(env->graphics.img.data, 0, WIN_W * WIN_H * env->graphics.img.bpp);
	put_world_on_image(&env->game, env->textures, &env->graphics.img);
	if (env->ui.is_minimap)
		put_minimap_on_image(env);
	mlx_put_image_to_window(env->graphics.mlx, env->graphics.win,
	env->graphics.img.ptr, 0, 0);
	if (env->ui.is_fire)
	{
		weapon_animation_index = get_next_weapon_animation_index(env);
		mlx_put_image_to_window(env->graphics.mlx, env->graphics.win,
		env->textures[weapon_animation_index].img.ptr, WEAPON_X, WEAPON_Y);
	}
	else
	{
		mlx_put_image_to_window(env->graphics.mlx, env->graphics.win,
		env->textures[WEAPON1].img.ptr, WEAPON_X, WEAPON_Y);
	}
	mlx_put_image_to_window(env->graphics.mlx, env->graphics.win,
	env->textures[HEALTH_BAR].img.ptr, HEALTH_BAR_X, HEALTH_BAR_Y);
}
