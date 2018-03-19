/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render_private.h"
#include "wolf3d_defines.h"
#include "libft.h"
#include "mlx.h"

void	render(t_env *env)
{
	ft_memset(env->graphics.img.data, 0, WIN_W * WIN_H * env->graphics.img.bpp);
	put_world_on_image(&env->game, env->textures, &env->graphics.img);
	mlx_put_image_to_window(env->graphics.mlx, env->graphics.win,
	env->graphics.img.ptr, 0, 0);
}