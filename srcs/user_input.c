/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:52:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:27:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "user_input.h"
#include "libft.h"

void	reset_user_input(t_user_input *ui)
{
	ft_memset(ui, 0, sizeof(*ui));
}
