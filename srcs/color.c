/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:08:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/01 20:14:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match_color(int x, int y, int **map)
{
	
	if (map[y][x] == 0)
		return (0x00FFFFFF);
	if (map[y][x] == 1)
		return (0x00FF0000);
	if (map[y][x] == 2)
		return (0x0000FF00);
	if (map[y][x] == 3)
		return (0x000000FF);
	if (map[y][x] == 4)
		return (0x00FFFFFF);
	return (0x00FFFFFF);
}
