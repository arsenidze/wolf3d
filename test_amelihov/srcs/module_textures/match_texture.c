/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_texture 		*match_texture(int value, int side, t_texture texs[])
{
	//TODO: look at side
	(void)side;
	return (texs[value - 1]);
}
