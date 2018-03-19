/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_world_on_image_private.h"
#include "raycasting.h"

t_texture	*match_tex(t_texture texs[], int value, int side)
{
	if (side == FLOOR_CEIL)
	{
		// printf("test1\n");
		return (&texs[0]);
	}
	if (value == 3)
	{
		// printf("test2\n");
		if ((side == west) || (side == east))
		{
			return (&texs[1]);
		}
		return (&texs[2]);
			
	}
	// printf("test3\n");
	return (&texs[value + 1]);
}