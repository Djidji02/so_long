/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:32:29 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/13 17:37:42 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

t_obj	get_map(int x, int y, t_state *state)
{
	if (x >= 0 && x < state->map.width && y >= 0 && y < state->map.height)
		return (state->map.tab[y * state->map.width + x]);
	else
		return (wall);
}
// imprimer du sol en dessous

void	set_map(int x, int y, t_state *state)
{
	if (x > 0 && x < state->map.width && y > 0 && y < state->map.height)
		state->map.tab[y * state->map.width + x] = floor;
}

/*
 * Fonction pour charger la map dans la struct sans les \n.
 */

int	fill_map(char *str, t_map *map)
{
	int	i;
	int	j;

	map->tab = malloc((map->width * map->height) * sizeof(t_obj));
	if (!map->tab)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			map->tab[j] = str[i];
			j++;
		}
		i++;
	}
	free (str);
	return (1);
}

/*
 * Positionner le joueur au depart
 */

void	player_start(t_state *state)
{
	int	i;
	int	j;

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

/*
 * Positionner l'ennemie  au depart
 */

void	enemy_start(t_state *state)
{
	int	i;
	int	j;

	state->enemy.eposy = -1;
	state->enemy.eposx = -1;
	j = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			if (get_map(i, j, state) == enemy)
			{
				state->enemy.eposx = i;
				state->enemy.eposy = j;
			}
			i++;
		}
		j++;
	}
}
