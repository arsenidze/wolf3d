/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:52:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/07 14:52:54 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINPUT_H
# define USERINPUT_H

typedef unsigned char	t_byte;

typedef struct 			s_userinput
{
	t_byte	motion;
	t_byte	rotation;
}						t_userinput;

void					reset_userinput(t_userinput *ui);

#endif
