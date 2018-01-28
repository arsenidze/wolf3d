/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 22:29:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/28 18:24:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#define WIN_W 800
#define WIN_H 800

typedef double	t_vect2d __attribute__((vector_size(sizeof(double)*2)));
//typedef int		t_vect2i __attribute__((vector_size(sizeof(int)*2)));

#define X 0
#define Y 1

typedef struct	s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
	t_vect2d	plane;
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

typedef struct	s_user_input
{

}				t_user_input;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_user_input	ui;
	t_game			game;
}				t_env;

#define SUCCESS 0

short			init(t_env *env, int **map, int w, int h);
void			del(t_env *env);

void			init_game(t_game *game, int **coord, int w, int h);

/*
** Event codes for mlx_hook
*/
#define KEY_PRESS 2
#define DESTROY_NOTIFY 17

int				key_press_hook(int keycode, void *arg);
int				exit_hook(void *arg);
int				loop_hook(void *arg);

short			is_valid(char **lines);
int				**create_map(char **line, int *w, int *h);
void			*free_map(int ***map);

void			draw(t_env *env);
int				get_color(int x, int y, int **map);

void	move(t_player *hero, t_map *map, float step);
void	rotate(t_player *hero, t_map *map, float angle);

#endif
