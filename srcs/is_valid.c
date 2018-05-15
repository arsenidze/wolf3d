/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:23:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/27 21:38:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_one_of(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

#define FIRST_LINE_VALID_CHARS		"1234567"
#define MIDDLE_LINES_VALID_CHARS	"01234567"
#define LAST_LINE_VALID_CHARS		"1234567"
#define FLOOR_CHAR '0'

static int	is_line_with_valid_chars(char *line, char *valid_chars,
			int *out_len)
{
	int		i;

	if (line[0] == FLOOR_CHAR)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!is_one_of(line[i], valid_chars))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	if (line[i - 1] == FLOOR_CHAR)
		return (0);
	*out_len = i;
	return (1);
}

short		is_valid(char **lines)
{
	int		first_line_len;
	int		curr_line_len;
	int		i;

	first_line_len = 0;
	curr_line_len = 0;
	if (!lines[0] || !is_line_with_valid_chars(lines[0],
		FIRST_LINE_VALID_CHARS, &first_line_len) || (first_line_len < 3))
		return (0);
	i = 0;
	while (lines[++i])
	{
		if (!is_line_with_valid_chars(lines[i],
			MIDDLE_LINES_VALID_CHARS, &curr_line_len))
			return (0);
		if (first_line_len != curr_line_len)
			return (0);
	}
	if ((i < 3) || !is_line_with_valid_chars(lines[i - 1],
		LAST_LINE_VALID_CHARS, &curr_line_len))
		return (0);
	if (first_line_len != curr_line_len)
		return (0);
	return (1);
}
