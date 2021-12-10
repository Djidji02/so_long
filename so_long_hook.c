/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_kook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:41:54 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/08 21:02:42 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_state *state)
{
	(void) state;
	exit(10);
}

int	move(int x, int y, t_state *state)
{
	return (get_map(state->posx + x, state->posy + y, state) != wall);
}

void	key_code(int keycode, t_state *state)
{
	if (keycode == KEY_EXIT)
		exit_hook(state);
	else if (keycode == KEY_UP && move (0, -1, state))
	{
		state->posy--;
		state->move++;
	}
	else if (keycode == KEY_LEFT && move (-1, 0, state))
	{
		state->posx--;
		state->move++;
	}
	else if (keycode == KEY_DOWN && move (0, +1, state))
	{
		state->posy++;
		state->move++;
	}
	else if (keycode == KEY_RIGHT && move(+1, 0, state))
	{
		state->posx++;
		state->move++;
	}
	if (get_map(state->posx, state->posy, state) == object)
		set_map(state->posx, state->posy, state);
}
/*
 *	Nettoyer la window avant de print
 */

void	map(t_state *state)
{
	char	*nb;

	nb = ft_itoa(state->move);
	mlx_clear_window(state->mlx, state->win);
	print_map(state);
	if (nb)
	{
		mlx_string_put(state->mlx, state->win, state->posx * 16, state->posy * 16, 0x00111111, nb);
		free (nb);
	}
}

int	key_hook(int keycode, t_state *s)
{
	int	i;
	int	j;
	int	obj;

	key_code(keycode, s);
	j = 0;
	obj = 0;
	while (j < s->map.height)
	{
		i = 0;
		while (i < s->map.width)
		{
			if (get_map(i, j, s) == object)
				obj++;
			i++;
		}
		j++;
	}
	if (obj == 0)
		if (get_map(s->posx, s->posy, s) == finish)
			exit_hook(s);
	map(s);
	mlx_put_image_to_window(s->mlx, s->win, s->player.image,
		s->posx * s->player.width, s->posy * s->player.height);
	return (0);
}
