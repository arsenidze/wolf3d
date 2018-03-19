/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 20:01:56 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#define INITIAL_POS (t_vect2d){1.5, 1.5}
#define DEFAULT_DIR (t_vect2d){0., 1.}
#define DEFAULT_PLANE (t_vect2d){1.3, 0.0}

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));

typedef struct 	s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
	t_vect2d	plane;
}				t_player;

void			init_player(t_player *player);

#endif
