/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:03:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/02 18:03:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/includes/libft.h"
#include "./module_wolf3d/wolf3d.h"
#include "./module_game/game.h"
#include "./module_errors/errors.h"
#include "./module_controllers/controllers.h"

static int 	print_and_ret(char *s)
{
	ft_putstr("Error: ");
	ft_putendl(s);
	return (FAILURE);
}

int 		main(void)
{
	t_env	env;

	if (init_graphics(&env.view) != SUCCESS)
		return (print_and_ret(get_err()));
	if (init_textures(env.textures, &env.view) != SUCCESS)
		return (print_and_ret(get_err()));
	if (init_game(&env.game) != SUCCESS)
		return (print_and_ret(get_err()));
	init_controllers(&env);
	run_loop(&env);
	return (SUCCESS);
}
