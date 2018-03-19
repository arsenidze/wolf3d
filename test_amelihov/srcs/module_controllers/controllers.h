/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:10:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 10:10:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLERS_H
# define CONTROLLERS_H

void	init_controllers(void *v_env);
int		keyboard_press_controller(int keycode, void *v_env);
int		keyboard_release_controller(int keycode, void *v_env);
int 	quit_contorller(void *v_env);

#endif
