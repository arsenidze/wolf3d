/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:34:17 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/27 21:34:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "../module_graphics/graphics.h"

static char	**get_texs_names(void)
{
	static char	*texs_names[NTEXTURES] = {
		PATH_TEXS"greystone.xpm",
		PATH_TEXS"wall.xpm"
	};

	return (texs_names);
}

static void	init_textures_failure(t_texture texs_arr[], t_graphics *view, char *err)
{
	deinit_textures(texs_arr, view);
	try_set_err(err);
}

short		init_textures(t_texture texs_arr[], t_graphics *view)
{
	char		**texs_names;
	int			i;

	texs_names = get_texs_names();
	i = 0;
	while (i < NTEXTURES)
	{
		if (!(texs_arr[i].img.ptr = mlx_xpm_file_to_image(view->mlx,
		texs_names[i], &texs_arr[i].w, &texs_arr[i].h)))
		{
			init_textures_failure(texs_arr, view, MLX_XPM_FILE_TO_IMAGE_FAILURE);
			return (FAILURE);
		}
		texs_arr[i].img.data = mlx_get_data_addr(texs_arr[i].img.ptr,
		&texs_arr[i].img.bpp, &texs_arr[i].img.sl, &texs_arr[i].img.endian);
		i++;
	}
	return (SUCCESS);
}

void		deinit_textures(t_texture texs_arr[], t_graphics *view)
{
	int		i;

	i = 0;
	while (i < NTEXTURES && texs_arr[i].img.ptr)
	{
		mlx_destroy_image(view->mlx, texs_arr[i].img.ptr);
		i++;
	}
}