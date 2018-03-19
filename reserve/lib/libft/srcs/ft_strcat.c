/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:07:42 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/26 13:15:08 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*p;

	p = s1;
	while (*p != '\0')
		p++;
	while ((*p++ = *s2++) != '\0')
		;
	return (s1);
}