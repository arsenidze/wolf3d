/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:27:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/06 12:27:42 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include "errors.h"

/*
**	set_err:
**	setter to error variable
*/
void	set_err(char *err);

/*
**	get_err:
**	getter for error variable
*/
char	*get_err(void);

/*
**	try_set_err:
**	check if error variable is NULL then set it to input char *err
*/
void	try_set_err(char *err);

#define MLX_INIT_FAILURE 		"Failed to initialize mlx (mlx_init)"
#define MLX_NEW_WINDOW_FAILURE 	"Failed to create new window (mlx_new_window)"
#define MLX_NEW_IMAGE_FAILURE 	"Failed to create new image (mlx_new_image)"
#define INIT_MAP_FAILURE		"Failed to init map"

#define FILE_READING_FAILURE	"Problems with map file"
#define FILE_VALIDATION_FAILURE "Map file is unvalid"
#define MEMORY_FAILURE			"Not enough memory"

#define MLX_XPM_FILE_TO_IMAGE_FAILURE "Failed to load xpm image (mlx_xpm_file_to_image)"

#endif
