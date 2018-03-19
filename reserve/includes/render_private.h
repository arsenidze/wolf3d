/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PRIVATE_H
# define RENDER_PRIVATE_H

#include "game.h"
#include "graphics.h"

typedef struct 	s_vline
{
	int x;
	int	top;
	int bottom;
	int len;
}				t_vline;

void		put_world_on_image(t_game *game, t_texture texs[], t_image *img);
t_texture	*match_tex(t_texture texs[], int value, int side);


#endif
