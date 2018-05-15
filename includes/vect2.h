/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:11:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 20:02:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_H
# define VECT2_H

# include <math.h>

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));
typedef int		t_vect2i __attribute__((vector_size(sizeof(int)*2)));

# define X 0
# define Y 1

# define VECT2_MULL_ON_SCALAR(v, a) (v * (t_vect2d){a, a})
# define VECT2_DIV_ON_SCALAR(v, a) (v / (t_vect2d){a, a})
# define VECT2_LEN(v) (sqrt(v[X] * v[X] + v[Y] * v[Y]))
# define VECT2_NORM(v) VECT2_DIV_ON_SCALAR(v, VECT2_LEN(v))
# define VECT2_ROTATE(v, a) ((t_vect2d){VROTATE_X(v, a), VROTATE_Y(v, a)})
# define VROTATE_X(v, a) (v[X] * cos(a) - v[Y] * sin(a))
# define VROTATE_Y(v, a) (v[X] * sin(a) + v[Y] * cos(a))

#endif
