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

#include "env.h"
#include "controllers.h"
#include "errors.h"
#include "libft.h"

static int	print_and_ret(char *s)
{
	ft_putendl(s);
	return (1);
}

int			main(void)
{
	t_env	env;

	// if (init_graphics(&env.graphics) != SUCCESS)
	// 	return (print_and_ret(get_err()));
	// if (init_textures(env.textures, &env.graphics) != SUCCESS)
	// 	return (print_and_ret(get_err()));
	// if (init_game(&env.game) != SUCCESS)
	// 	return (print_and_ret(get_err()));
	// init_controllers(&env);

	if (env_init(&env) != SUCCESS)
		return (print_and_ret(get_err()));
	controllers_init(&env);
	run_event_handler_loop(&env);
	return (SUCCESS);
}
