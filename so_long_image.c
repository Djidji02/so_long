/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:22:54 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/13 17:18:01 by snadji-h         ###   ########.fr       */
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
//xor operation 

int	animation(t_state *state)
{
	if (state->posx % 2 != 0 ^ state->posy % 2 == 0)
		return (1);
	else
		return (0);
}
/*
 * Print player with bonus
 */

void	print_player(t_state *s)
{
	if (animation(s))
		mlx_put_image_to_window(s->mlx, s->win, s->player.image,
			s->posx * s->player.width, s->posy * s->player.height);
	else
		mlx_put_image_to_window(s->mlx, s->win, s->player2.image,
			s->posx * s->player2.width, s->posy * s->player2.height);
}

void	print_enemy(t_state *s)
{
	if (animation(s))
		mlx_put_image_to_window(s->mlx, s->win, s->enemy_image.image,
			s->enemy.eposx * s->enemy_image.width,
			s->enemy.eposy * s->enemy_image.height);
	else
		mlx_put_image_to_window(s->mlx, s->win, s->enemy2_image.image,
			s->enemy.eposx * s->enemy2_image.width,
			s->enemy.eposy * s->enemy2_image.height);
}

/*
 * Charger les images avce le mlx
 */

void	print_map(t_state *state)
{
	int	i;
	int	j;
	int	o;

	j = 0;
	while (j < state->map.height)
	{
		i = 0;
		while (i < state->map.width)
		{
			o = get_map(i, j, state);
			if (o == wall)
				so_long_put_image(state, &state->wall, i, j);
			else if (o == object)
				(so_long_put_image(state, &state->floor, i, j),
					so_long_put_image(state, &state->object, i, j));
			else if (o == floor || o == start || o == enemy)
				so_long_put_image(state, &state->floor, i, j);
			else if (o == finish)
				so_long_put_image(state, &state->finish, i, j);
			i++;
		}
		j++;
	}
}
