/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/02/26 16:42:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdio.h>
#include "libft.h"

#define WIN_W 800
#define WIN_H 800

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));
typedef int		t_vect2i __attribute__((vector_size(sizeof(int)*2)));

#define X 0
#define Y 1

typedef struct	s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
	t_vect2d	plane;
	float		colider_radius;
}				t_player;

typedef struct	s_map
{
	int		**coord;
	int		w;
	int		h;
}				t_map;

typedef struct	s_game
{
	t_map		map;
	t_player	player;
}				t_game;

typedef struct	s_image
{
	void	*ptr;
	char	*data;
	int		sl;
	int		bpp;
	int		endian;
}				t_image;

typedef struct	s_texture
{
	t_image	img;
	int		w;
	int		h;
}				t_texture;

typedef struct	s_user_input
{
	t_byte	motion;
	t_byte	rotation;
}				t_user_input;

#define NTEXTURES 2

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_texture		texs[NTEXTURES];
	t_user_input	ui;
	t_game			game;
}				t_env;

typedef struct 	s_range_in_img
{
	int 	x;
	int 	y_top;
	int 	y_bottom;
}				t_range_in_img;

#define SUCCESS 0

short			init_env(t_env *env, int **map, int w, int h);
void			deinit_env(t_env *env);

void			init_game(t_game *game, int **coord, int w, int h);
void			reset_user_input(t_user_input *ui);

/*
** Event codes for mlx_hook
*/
#define KEY_PRESS 		2
#define KEY_RELEASE		3
#define DESTROY_NOTIFY	17

int				key_press_hook(int keycode, void *arg);
int				key_release_hook(int keycode, void *arg);
int				exit_hook(void *arg);
int				loop_hook(void *arg);

short			is_valid(char **lines);
int				**create_map(char **line, int *w, int *h);
void			*free_map(int ***map);

void			draw(t_env *env);
double			get_x_in_texture(t_vect2d hit, t_vect2d dir, int **map);
t_range_in_img	get_range_in_img(int x, t_vect2d hit, t_vect2d ray_dir,
				t_player *player);
t_vect2i		get_coord_on_map(t_vect2d pos, t_vect2d ray_dir);

int				match_color(int x, int y, int **map);

void			move(t_player *hero, t_map *map, t_byte motion);
void			rotate(t_player *hero, t_map *map, t_byte rotation);

short			init_textures(t_env *env);
void			deinit_textures(t_env *env);
t_texture		*get_texture(t_vect2d hit, t_vect2d dir, int **map, t_env *env);

#endif
