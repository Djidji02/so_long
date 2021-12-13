/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:29:41 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/13 17:37:50 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// obtenir largeur/longeur map 

int	size_map(char *str, t_map *map)
{
	int	i;
	int	current_line;

	i = 0;
	map->width = 0;
	while (str[i] && str[i++] != '\n')
		map->width ++;
	map->height++;
	while (str[i])
	{
		current_line = 0;
		while (str[i] && str[i++] != '\n')
			current_line++;
		if (current_line != map->width)
			return (0);
		map->height++;
	}
	return (1);
}

int	valid_map(t_state *state)
{
	int	i;
	int	obj;

	i = 0;
	while (i < state->map.width * state->map.height)
	{
		obj = state->map.tab[i];
		if (!(obj == wall || obj == finish || obj == floor
				|| obj == enemy || obj == start || obj == object))
			return (0);
		i++;
	}
	return (1);
}
// Verifier les murs

int	init_check_map(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->map.width)
	{
		if ((get_map(i, 0, state) != wall)
			|| (get_map(i, state->map.height - 1, state) != wall))
			return (0);
		i++;
	}
	i = 0;
	while (i < state->map.height)
	{
		if ((get_map(0, i, state) != wall)
			|| (get_map(state->map.width - 1, i, state) != wall))
			return (0);
		i++;
	}
	return (1);
}
// Verifier une sortie/ un depart

int	check_map(t_state *state)
{
	int	i;
	int	j;
	int	n;

	if (!(init_check_map(state)))
		return (0);
	i = 0;
	j = 0;
	n = 0;
	while (i < state->map.width * state->map.height)
	{
		if (state->map.tab[i] == start)
			n++;
		if (state->map.tab[i] == finish)
			j++;
		i++;
	}
	if (j != 1 || n != 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	t_state	state;

	state = (t_state){0};
	state.mlx = mlx_init();
	if (ac != 2)
		return (printf("Revoie tes arguments fdp \n"), 0);
	str = read_map(av[1]);
	if (!size_map(str, &state.map) || !fill_map(str, &state.map)
		|| !valid_map(&state) || !check_map(&state))
		return (printf("Error\n"), 0);
	mlx_setup(&state);
}
