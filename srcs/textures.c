/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:34:17 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 16:01:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "errors.h"
#include "wolf3d_defines.h"
#include "mlx.h"

static char	**get_texs_names(void)
{
	static char	*texs_names[NTEXTURES] = {
		PATH_TEXS"greystone.xpm",
		PATH_TEXS"redbrick.xpm",
		PATH_TEXS"eagle.xpm",
		PATH_TEXS"colorstone.xpm",
		PATH_TEXS"mossy.xpm",
		PATH_TEXS"purplestone.xpm",
		PATH_TEXS"wood.xpm",
		PATH_TEXS"weapon1.xpm",
		PATH_TEXS"weapon2.xpm",
		PATH_TEXS"weapon3.xpm",
		PATH_TEXS"weapon4.xpm",
		PATH_TEXS"health_bar.xpm",
	};

	return (texs_names);
}

static void	textures_init_failure(t_texture texs_arr[],
			t_graphics *view, char *err)
{
	textures_deinit(texs_arr, view);
	try_set_err(err);
}

short		textures_init(t_texture texs_arr[], t_graphics *view)
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
			textures_init_failure(texs_arr, view,
				MLX_XPM_FILE_TO_IMAGE_FAILURE);
			return (FAILURE);
		}
		texs_arr[i].img.data = mlx_get_data_addr(texs_arr[i].img.ptr,
		&texs_arr[i].img.bpp, &texs_arr[i].img.sl, &texs_arr[i].img.endian);
		texs_arr[i].img.bpp /= 8;
		i++;
	}
	return (SUCCESS);
}

void		textures_deinit(t_texture texs_arr[], t_graphics *view)
{
	int		i;

	i = 0;
	while (i < NTEXTURES && texs_arr[i].img.ptr)
	{
		mlx_destroy_image(view->mlx, texs_arr[i].img.ptr);
		i++;
	}
}
