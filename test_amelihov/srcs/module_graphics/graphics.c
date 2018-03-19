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
#include "../module_wolf3d/wolf3d.h"
#include "stddef.h"

static void	init_grahics_failure(t_graphics *view, char *err)
{
	deinit_graphics(view);
	try_set_err(err);
}

void		deinit_graphics(t_graphics *view)
{
	if (view->win)
		mlx_destroy_window(view->mlx, view->win);
	if (view->img.ptr)
		mlx_destroy_image(view->mlx, view->img.ptr);
}

short		init_graphics(t_graphics *view)
{
	view->win = NULL;
	view->img.ptr = NULL;
	if (!(view->mlx = mlx_init()))
	{
		init_grahics_failure(view, MLX_INIT_FAILURE);
		return (FAILURE);
	}
	if (!(view->win = mlx_new_window(view->mlx, WIN_W, WIN_H, PROGNAME)))
	{
		init_grahics_failure(view, MLX_NEW_WINDOW_FAILURE);
		return (FAILURE);
	}
	if (!(view->img.ptr = mlx_new_image(view->mlx, WIN_W, WIN_H)))
	{
		init_grahics_failure(view, MLX_NEW_IMAGE_FAILURE);
		return (FAILURE);
	}
	view->img.data = mlx_get_data_addr(view->img.ptr, &view->img.bpp,
	&view->img.sl, &view->img.endian);
	view->img.bpp /= 8;
	return (SUCCESS);
}
