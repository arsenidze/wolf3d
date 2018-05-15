/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:15:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/25 18:50:22 by amelihov         ###   ########.fr       */
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

	if (env_init(&env) != SUCCESS)
		return (print_and_ret(get_err()));
	controllers_init(&env);
	run_event_handler_loop(&env);
	return (SUCCESS);
}
