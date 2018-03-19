/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:47:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/22 21:39:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define NOBJECTS 1
#define FLOOR '0'

#define IN_RANGE(c, range) ((c) >= range[0] && (c) <= range[2])

#define SPACES(c) ((c) == ' ' || (c) == '\t')

short	is_line_with_valid_chars(char *line, int *out_len,
		char *valid_chars_range)
{
	int		i;

	if (line[0] == FLOOR)
		return (0);
	i = 1;
	while (line[i])
	{
		if (!IN_RANGE(line[i], valid_chars_range))
			return (0);
		i++;
	}
	if (line[i - 1] == FLOOR)
		return (0);
	*out_len = i;
	return (1);
}

#define FIRST_LINE 0
#define LAST_LINE 0
#define NOT_FIRST_LINE 1

/*
**	0 - floor
*/

#define FIRST_LINE_RANGE "1-1"
#define NOT_FIRST_LINE_RANGE "0-1"

short	is_valid(char **lines)
{
	int		i;
	int		curr_line_len;
	int		first_line_len;
	char	*valid_chars[2];

	valid_chars[0] = FIRST_LINE_RANGE;
	valid_chars[1] = NOT_FIRST_LINE_RANGE;
	curr_line_len = 0;
	first_line_len = 0;
	if (!is_line_with_valid_chars(lines[0], &first_line_len,
		valid_chars[FIRST_LINE]))
		return (0);
	if (first_line_len < 3)
		return (0);
	i = 1;
	while (lines[i])
	{
		if (!is_line_with_valid_chars(lines[i], &curr_line_len,
			valid_chars[NOT_FIRST_LINE]))
			return (0);
		if (curr_line_len != first_line_len)
			return (0);
		i++;
	}
	if (!is_line_with_valid_chars(lines[i - 1], &curr_line_len,
		valid_chars[LAST_LINE]))
		return (0);
	if (curr_line_len != first_line_len)
		return (0);
	if (i < 3)
		return (0);
	return (1);
}
