/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:59:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/08 10:03:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "../module_game/game.h"
#include "../module_textures/textures.h"
#include "../module_errors/errors.h"
#include "../../lib/mlx/mlx.h"

#define SUCCESS 0
#define FAILURE 1

typedef struct	s_image
{
	void	*ptr;
	char	*data;
	int		sl;
	int		bpp;
	int		endian;
}				t_image;

typedef struct 	s_graphics
{
	void	*mlx;
	void	*win;
	t_image	img;

}				t_graphics;

short			init_graphics(t_graphics *graphics);
void			deinit_graphics(t_graphics *graphics);
void			render(t_game *game, void *texs_arr, t_graphics *view);

#endif
