/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:29:41 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/09 14:43:00 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_setup(t_state *state)
{
	state->player.image = mlx_xpm_file_to_image(state->mlx, "player.xpm",
			&state->player.width, &state->player.height);
	//state->player.image = mlx_xpm_file_to_image(state->mlx, "player2.xpm",
			//&state->player.width, &state->player.height);
	state->wall.image = mlx_xpm_file_to_image(state->mlx, "wall.xpm",
			&state->wall.width, &state->wall.height);
	state->object.image = mlx_xpm_file_to_image(state->mlx, "object.xpm",
			&state->object.width, &state->object.height);
	state->floor.image = mlx_xpm_file_to_image(state->mlx, "floor.xpm",
			&state->floor.width, &state->floor.height);
	state->finish.image = mlx_xpm_file_to_image(state->mlx, "exit.xpm",
			&state->finish.width, &state->finish.height);
	state->win = mlx_new_window(state->mlx, state->map.width * 16,
			state->map.height * 16, "so_long");
	player_start(state);
	printf("1\n");
	mlx_hook(state->win, 17, 0, exit_hook, state);
	printf("2\n");
	mlx_hook(state->win, 2, 0, key_hook, state);
	printf("4\n");
	mlx_loop(state->mlx);
}
