/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:01:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/26 21:48:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_init(t_player *player)
{
	player->pos = INITIAL_POS;
	player->dir = DEFAULT_DIR;
	player->speed = DEFAULT_SPEED;
}
