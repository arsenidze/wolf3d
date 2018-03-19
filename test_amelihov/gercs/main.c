/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:15:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/22 22:05:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include "mlx.h"

static int	print_and_ret(char *s)
{
	ft_putendl(s);
	return (1);
}

#include <stdio.h>

int			main(int argc, char **argv)
{
	char	**lines;
	int		**map;
	int		w;
	int		h;
	t_env	env;
	
	if (0 && argc != 2)
		return (print_and_ret("usage: ./wolf3d <file_name>"));
	if (!(lines = read_file((argc == 2) ? argv[1] : "test")))
		return (print_and_ret("wolf3d: Problem with file reading"));
	if (!is_valid(lines))
		return (print_and_ret("wolf3d: Invalid file"));
	if (!(map = create_map(lines, &w, &h)))
		return (print_and_ret("wolf3d: Problem with map creation"));
	if (init_env(&env, map, w, h) != SUCCESS)
		return (print_and_ret("wolf3d: Problem with initialization"));	
	mlx_hook(env.win, KEY_PRESS, 0, key_press_hook, &env);
	mlx_hook(env.win, KEY_RELEASE, 0, key_release_hook, &env);
	mlx_hook(env.win, DESTROY_NOTIFY, 0, exit_hook, &env);	
	mlx_loop_hook(env.mlx, loop_hook, &env);
	draw(&env);
	mlx_loop(env.mlx);
}
