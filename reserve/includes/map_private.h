/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PRIVATE_H
# define MAP_PRIVATE_H

short	is_valid(char **lines);
int		**lines_to_2d_arr(char **lines, int *w, int *h);
void	*free_map(int ***map);
void	free_lines(char ***lines);

#endif
