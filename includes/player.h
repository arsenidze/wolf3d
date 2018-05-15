/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 20:09:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define INITIAL_POS 		(t_vect2d){1.5, 1.5}
# define DEFAULT_DIR 		(t_vect2d){0., 1.}
# define DEFAULT_SPEED		0.1
# define ACCELERATION_SPEED	(DEFAULT_SPEED * 2.0)
# define DECELERATION_SPEED	(DEFAULT_SPEED / 2.0)
# define ROTATE_ANGLE		(3 * M_PI / 180.0)

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));

typedef struct	s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
	float		speed;
}				t_player;

void			player_init(t_player *player);

#endif
