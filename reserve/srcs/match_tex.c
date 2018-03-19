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

#include "render_private.h"
#include "raycasting.h"

t_texture	*match_tex(t_texture texs[], int value, int side)
{
	(void)side;
	if (side < 0)
		return (&texs[value]);
	if (value == 3)
	{
		if ((side == west) || (side == east))
		{
			// printf("testsets");
			// printf("t_w: %d t_h: %d %p\n", texs[1].w, texs[1].h, &texs[1]);
			return (&texs[1]);
		}
		return (&texs[2]);
			
	}
	return (&texs[value]);
}