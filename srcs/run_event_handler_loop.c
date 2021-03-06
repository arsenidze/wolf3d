/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_event_handler_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:43:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "mlx.h"

void	run_event_handler_loop(t_env *env)
{
	mlx_loop(env->graphics.mlx);
}
