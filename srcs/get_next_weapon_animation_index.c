/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_weapon_animation_index.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:36:20 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:52:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_weapon_animation_index.h"
#include "graphics.h"
#include "mlx.h"

#define FRAMES_ON_ANIMATION_CHANGE 5

int		get_next_weapon_animation_index(t_env *env)
{
	static int	curr_animation_index = WEAPON1;
	static int	frame_iter = 0;

	frame_iter++;
	if (frame_iter % FRAMES_ON_ANIMATION_CHANGE == 0)
		curr_animation_index++;
	if (curr_animation_index > WEAPON_LAST_INDEX)
	{
		frame_iter = 0;
		curr_animation_index = WEAPON1;
		env->ui.is_fire = 0;
	}
	return (curr_animation_index);
}
