/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:29:41 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/30 21:49:34 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int exit_hook(t_state *state)
{
	(void) state;
	exit(10);
}

t_obj get_map(int x, int y, t_state *state)
{
	if (x > 0 && x < state->map.width && y > 0 && y < state->map.height)
		return (state->map.tab[y* state->map.width + x]);
	else
		return (wall);
}

void	set_map(int x, int y, t_state *state)
{
	if (x > 0 && x < state->map.width && y > 0 && y < state->map.height)
		state->map.tab[y* state->map.width + x] = floor;
}

void	print_map(t_state *state)
{
	int i;
	int j;

	j = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			if (get_map(i, j, state) == wall)
			mlx_put_image_to_window(state->mlx, state->win, state->wall.image, i*state->wall.width, j*state->wall.height);
			else if (get_map(i, j, state) == object)
			mlx_put_image_to_window(state->mlx, state->win, state->object.image, i*state->object.width, j*state->object.height);
			else if (get_map(i, j, state) == floor || get_map(i, j, state) == start)
			mlx_put_image_to_window(state->mlx, state->win, state->floor.image, i*state->floor.width, j*state->floor.height);
			else if (get_map(i, j, state) == finish)
			mlx_put_image_to_window(state->mlx, state->win, state->finish.image, i*state->finish.width, j*state->finish.height);
			i++;
		}
		j++;
	}
}

void	player_start(t_state *state)
{
	int i;
	int j;

	j = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			if (get_map(i, j, state) == start)
			{
				state->posx = i;
				state->posy = j;
			}
			i++;
		}
		j++;
	}
}

int key_hook(int keycode, t_state *state)
{
	int i;
	int j;
	int obj;

	if (keycode == KEY_EXIT)
		exit_hook(state);
	else if (keycode == KEY_UP && get_map(state->posx, state->posy - 1, state) != wall) 
		state->posy--;
	else if (keycode == KEY_LEFT && get_map(state->posx - 1, state->posy, state) != wall) 
		state->posx--;
	else if (keycode == KEY_DOWN && get_map(state->posx, state->posy +1 , state) !=wall)
		state->posy++;
	else if (keycode == KEY_RIGHT && get_map(state->posx + 1, state->posy, state) != wall) 
		state->posx++;
	if (get_map(state->posx, state->posy, state) == object)
		set_map(state->posx, state->posy, state);
	j = 0;
	obj = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			if (get_map(i, j, state) == object)
				obj++;
			i++;
		}
		j++;
	}
	if (obj == 0)
		if (get_map(state->posx, state->posy, state) == finish)
			exit_hook(state);
	printf("\nPLAYER\n x : %i \n y : %i \n ", state->posx, state->posy);
	mlx_clear_window(state->mlx, state->win);
	print_map(state);
	mlx_put_image_to_window(state->mlx, state->win, state->player.image, state->posx*state->player.width, state->posy*state->player.height);
	printf("\nKeycode : %i \n", keycode);
	printf("----------------");
	return (0);
}

int mouse_hook(int button,int x,int y, t_state *state)
{
	(void) state;
	printf("button : %i \n", button);
	return (0);
}

int main()
{
	t_state state;
	
	state  = (t_state){0};
    state.mlx = mlx_init();
    state.map.width = 9;
    state.map.height = 9;
	state.map.tab = (t_obj[]){
		wall, wall, wall, floor, wall, wall,wall, wall, wall,
		wall, finish, floor, floor, floor, floor, floor, floor, wall,
		wall, floor, floor, floor, object, floor, floor, floor, wall,
		wall, floor, object, floor, floor, floor, floor, floor, wall,
		wall, floor, floor, start, floor, floor, floor, floor, wall,
		wall, floor, floor, floor, floor, floor, floor, floor, wall,
		wall, floor, object, floor, floor, floor, floor, floor, wall,
		wall, floor, floor, floor, floor, floor, floor, floor, wall,
		wall, wall, wall, wall, wall, wall, wall, wall, wall};
	state.player.image = mlx_xpm_file_to_image(state.mlx, "player.xpm", &state.player.width, &state.player.height);
	state.wall.image = mlx_xpm_file_to_image(state.mlx, "wall.xpm", &state.wall.width, &state.wall.height);
	state.object.image = mlx_xpm_file_to_image(state.mlx, "object.xpm", &state.object.width, &state.object.height);
	state.floor.image = mlx_xpm_file_to_image(state.mlx, "floor.xpm", &state.floor.width, &state.floor.height);
	state.finish.image = mlx_xpm_file_to_image(state.mlx, "exit.xpm", &state.finish.width, &state.finish.height);
    state.win = mlx_new_window(state.mlx, state.map.width * 16, state.map.height * 16, "so_long");
	player_start(&state);
	mlx_hook(state.win, 17, 0, exit_hook, &state);
	mlx_mouse_hook(state.win, mouse_hook, &state);
	mlx_hook(state.win, 2, 0, key_hook, &state);
	mlx_loop(state.mlx);
}
