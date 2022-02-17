/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:29:41 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/13 17:37:49 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_load_image(t_state *state)
{
	state->player.image = mlx_xpm_file_to_image(state->mlx, "player.xpm",
			&state->player.width, &state->player.height);
	state->player2.image = mlx_xpm_file_to_image(state->mlx, "player2.xpm",
			&state->player2.width, &state->player2.height);
	state->enemy_image.image = mlx_xpm_file_to_image(state->mlx, "enemy.xpm",
			&state->enemy_image.width, &state->enemy_image.height);
	state->enemy2_image.image = mlx_xpm_file_to_image(state->mlx, "enemy2.xpm",
			&state->enemy2_image.width, &state->enemy2_image.height);
	state->wall.image = mlx_xpm_file_to_image(state->mlx, "wall.xpm",
			&state->wall.width, &state->wall.height);
	state->object.image = mlx_xpm_file_to_image(state->mlx, "object.xpm",
			&state->object.width, &state->object.height);
	state->floor.image = mlx_xpm_file_to_image(state->mlx, "floor.xpm",
			&state->floor.width, &state->floor.height);
	state->finish.image = mlx_xpm_file_to_image(state->mlx, "exit.xpm",
			&state->finish.width, &state->finish.height);
	state->win = mlx_new_window(state->mlx, state->map.width * 32,
			state->map.height * 32, "so_long");
}

void	mlx_setup(t_state *state)
{
	mlx_load_image(state);
	player_start(state);
	enemy_start(state);
	print_everything(state);
	mlx_hook(state->win, 17, 0, exit_hook, state);
	mlx_hook(state->win, 2, 0, key_hook, state);
	mlx_loop(state->mlx);
}
