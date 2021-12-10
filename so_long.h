/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:01:36 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/09 14:42:46 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_EXIT 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0

typedef enum e_obj
{
	wall = '1',
	start = 'P',
	floor = '0',
	object = 'C',
	finish = 'E'
}	t_obj;

typedef struct s_map
{
	int		width;
	int		height;
	t_obj	*tab;
}	t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*image;
}	t_image;

typedef struct s_state
{
	int		posx;
	int		move;
	int		posy;
	void	*mlx;
	void	*win;
	t_image	player;
	t_image	player2;
	t_image	wall;
	t_image	object;
	t_image	finish;
	t_image	floor;
	t_map	map;
}	t_state;

char*	ft_itoa(int nb);
int		fill_map(char *str, t_map *map);
char	*read_map(char *path);
int		mouse_hook(int button, int x, int y, t_state *state);
char	*join(char *str, char *buffer, int count);
void	so_long_put_image(t_state *state, t_image *image, int i, int j);
int		mouse_hook(int button, int x, int y, t_state *state);
int		key_hook(int keycode, t_state *state);
int		exit_hook(t_state *state);
t_obj	get_map(int x, int y, t_state *state);
void	set_map(int x, int y, t_state *t_state);
void	print_map(t_state *state);
void	player_start(t_state *state);
void	mlx_setup(t_state *state);

#endif
