/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/21 20:15:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <stdlib.h>

#define TEXTURE_PATH "./textures"

static char	**get_texs_file_names(void)
{
	static char	*texs_names[NTEXTURES] = {
		/*
		TEXTURE_NAME(greystone.xpm),
		TEXTURE_NAME(wall.xpm)
		*/
		TEXTURE_PATH"/greystone.xpm",
		TEXTURE_PATH"/wall.xpm"
	};

	return (texs_names);
}

short		init_textures(t_env *env)
{
	char		**texs_names;
	int			i;

	texs_names = get_texs_file_names();
	i = 0;
	while (i < NTEXTURES)
	{
		if (!(env->texs[i].img.ptr = mlx_xpm_file_to_image(env->mlx,
		texs_names[i], &env->texs[i].w, &env->texs[i].h)))
		{
			printf("teststse\n");
			return (-1);
		}
		env->texs[i].img.data = mlx_get_data_addr(env->texs[i].img.ptr,
		&env->texs[i].img.bpp, &env->texs[i].img.sl, &env->texs[i].img.endian);
		i++;
	}
	return (0);
}

void		deinit_textures(t_env *env)
{
	int		i;

	i = 0;
	while (i < NTEXTURES && env->texs[i].img.ptr)
	{
		mlx_destroy_image(env->mlx, env->texs[i].img.ptr);
		i++;
	}
}

t_texture	*get_texture(t_vect2d hit, t_vect2d dir, int **map, t_env *env)
{
	t_vect2i	coord_on_map;
	short		coord_value;

	coord_on_map = get_coord_on_map(hit, dir);
	coord_value = map[coord_on_map[X]][coord_on_map[Y]];
	printf("map: %f %f\n", hit[X], hit[Y]);
	if (coord_value == 0 || coord_value > 2)
		coord_value = 1;
	printf("coord_value: %d\n", coord_value);
	return (&env->texs[coord_value - 1]);
}
