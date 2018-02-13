/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/13 15:13:09 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"
#include <stdlib.h>

static t_texture	*match_texture(void)
{
	static t_texture	tex1;

	return (&tex1);
}

void		init_textures(t_env *env)
{
	t_texture	*tex;

	tex = match_texture();
	if (!(tex->img.ptr = mlx_xpm_file_to_image(env->mlx, "wall.xpm",
		&tex->w, &tex->h)))
	{
		printf("texture.c line: %d\n", __LINE__);
		exit(1);
	}
	if (!(tex->img.data = mlx_get_data_addr(tex->img.ptr,
		&tex->img.bpp, &tex->img.sl, &tex->img.endian)))
	{
		printf("texture.c line: %d\n", __LINE__);
		exit(1);
	}
}

t_texture	*get_texture(t_vect2d hit, t_vect2d dir, int **map)
{
	(void)hit;
	(void)dir;
	(void)map;
	return (match_texture());
}
