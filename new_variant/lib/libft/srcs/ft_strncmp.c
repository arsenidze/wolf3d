/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:56:26 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/31 17:40:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*(t_byte *)s1 != *(t_byte *)s2 || *s1 == '\0')
			return (*(t_byte *)s1 - *(t_byte *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
