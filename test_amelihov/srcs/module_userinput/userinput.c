/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:52:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/07 14:52:54 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "userinput.h"
#include "../../lib/libft/includes/libft.h"

void	reset_userinput(t_userinput *ui)
{
	ft_memset(ui, 0, sizeof(*ui));
}