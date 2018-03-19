/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:59:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/08 10:02:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "wolf3d_defines.h"
#include "errors.h"
#include "mlx.h"
#include <stddef.h>

static void	graphics_init_failure(t_graphics *graphics, char *err)
{
	graphics_deinit(graphics);
	try_set_err(err);
}

void		graphics_deinit(t_graphics *graphics)
{
	if (graphics->win)
		mlx_destroy_window(graphics->mlx, graphics->win);
	if (graphics->img.ptr)
		mlx_destroy_image(graphics->mlx, graphics->img.ptr);
}

short		graphics_init(t_graphics *graphics)
{
	graphics->win = NULL;
	graphics->img.ptr = NULL;
	if (!(graphics->mlx = mlx_init()))
	{
		graphics_init_failure(graphics, MLX_INIT_FAILURE);
		return (FAILURE);
	}
	if (!(graphics->win = mlx_new_window(graphics->mlx, WIN_W, WIN_H, PROGNAME)))
	{
		graphics_init_failure(graphics, MLX_NEW_WINDOW_FAILURE);
		return (FAILURE);
	}
	if (!(graphics->img.ptr = mlx_new_image(graphics->mlx, WIN_W, WIN_H)))
	{
		graphics_init_failure(graphics, MLX_NEW_IMAGE_FAILURE);
		return (FAILURE);
	}
	graphics->img.data = mlx_get_data_addr(graphics->img.ptr, &graphics->img.bpp,
	&graphics->img.sl, &graphics->img.endian);
	graphics->img.bpp /= 8;
	return (SUCCESS);
}