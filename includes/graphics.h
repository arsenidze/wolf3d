/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:59:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 20:11:50 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "wolf3d_defines.h"

# define SUCCESS 0
# define FAILURE 1

# define WEAPON1			7
# define WEAPON2			8
# define WEAPON3			9
# define WEAPON4			10
# define WEAPON_LAST_INDEX	10
# define HEALTH_BAR			11

# define SET_PIXEL(i, x, y, c) *(int *)(i.data + (y) * i.sl + (x) * i.bpp) = c
# define GET_PIXEL(i, x, y) (*(int *)(i.data + (y) * i.sl + (x) * i.bpp))

typedef struct	s_image
{
	void	*ptr;
	char	*data;
	int		sl;
	int		bpp;
	int		endian;
}				t_image;

typedef struct	s_texture
{
	t_image	img;
	int		w;
	int		h;
}				t_texture;

typedef struct	s_graphics
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_texture	texs[NTEXTURES];
}				t_graphics;

short			graphics_init(t_graphics *graphics);
void			graphics_deinit(t_graphics *graphics);
short			textures_init(t_texture texs[], t_graphics *graphics);
void			textures_deinit(t_texture texs[], t_graphics *graphics);

#endif
