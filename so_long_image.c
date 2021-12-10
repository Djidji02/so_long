/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:54 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/10 15:41:44 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 * Fonction a appeler pour charger les image en fonction de l'object
 */
void	so_long_put_image(t_state *state, t_image *image, int i, int j)
{
	mlx_put_image_to_window(state->mlx, state->win,
		image->image, i * image->width,
		j * image->height);
}

int	animation(t_state *state)
{
	if (state->posx % 2 != 0 || state->posy % 2 != 0)
		return (1);
	else
		return (0);
}
/*
 * Charger les images avce le mlx
 */
void	print_map(t_state *state)
{
	int	i;
	int	j;

	j = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			if (get_map(i, j, state) == wall)
				so_long_put_image(state, &state->wall, i, j);
			else if (get_map(i, j, state) == object)
				so_long_put_image(state, &state->object, i, j);
			else if (get_map(i, j, state) == floor
				|| get_map(i, j, state) == start)
				so_long_put_image(state, &state->floor, i, j);
			else if (get_map(i, j, state) == finish)
				so_long_put_image(state, &state->finish, i, j);
			i++;
		}
		j++;
	}
}
