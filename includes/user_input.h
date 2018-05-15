/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:52:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 20:08:42 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

typedef unsigned char	t_byte;

typedef struct			s_user_input
{
	t_byte	motion;
	t_byte	rotation;
	t_byte	is_minimap;
	t_byte	is_fire;
	t_byte	is_acceleration;
	t_byte	is_deceleration;
}						t_user_input;

void					reset_user_input(t_user_input *ui);

#endif
