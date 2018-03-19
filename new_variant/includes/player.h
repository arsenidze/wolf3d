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

/*
**	1.15470053838 - 2 * tg(30deg)
**	30deg         - half of FOV
*/

#define INITIAL_POS (t_vect2d){1.6, 2.5}
#define DEFAULT_DIR (t_vect2d){0., -1.}
// #define DEFAULT_PLANE (t_vect2d){1.15470053838, 0.0}

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));

typedef struct 	s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
}				t_player;

void			player_init(t_player *player);

#endif
