/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:08:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/12 18:51:25 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match_color(int x, int y, int **map)
{
	
	if (map[y][x] == 0)
		return (0x0000FF00);
	if (map[y][x] == 1)
		return (0x00FF0000);
	if (map[y][x] == 2 || map[y][x] == 5)
		return (0x0000FF00);
	if (map[y][x] == 3)
		return (0x000000FF);
	if (map[y][x] == 4)
		return (0x00FFFFFF);	
	return (-1);
}
