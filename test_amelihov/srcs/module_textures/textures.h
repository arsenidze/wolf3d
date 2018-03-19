/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:34:17 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/27 21:34:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

#include "../module_errors/errors.h"
#include "../module_graphics/graphics.h"

#define SUCCESS 0
#define FAILURE 1

#define NTEXTURES 2
#define PATH_TEXS "./resources/textures/"

// #define TEXS_W 256
// #define TEXS_H 256

typedef struct	s_texture
{
	t_image	img;
	int		w;
	int		h;
}				t_texture;

short			init_textures(t_texture texs_arr[], t_graphics *view);
void			deinit_textures(t_texture texs_arr[], t_graphics *view);
t_texture 		*match_texture(int value, int side, t_texture texs_arr[]);

#endif
