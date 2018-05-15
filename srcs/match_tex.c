/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 15:52:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_world_on_image_private.h"
#include "raycasting.h"

t_texture	*match_tex(t_texture texs[], int value, int side)
{
	if (value == DIFF_SIDES)
	{
		if (side == south)
			return (&texs[REDWALL]);
		if (side == east)
			return (&texs[STONE]);
		if (side == west)
			return (&texs[REDWALL]);
		if (side == north)
			return (&texs[AXIDSTONE]);
	}
	return (&texs[value]);
}
