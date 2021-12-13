/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:08:17 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/13 17:19:29 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemie(t_state *state)
{	
	if (state->enemy.direction == 0)
	{
		if (get_map(state->enemy.eposx + 1, state->enemy.eposy, state) != wall)
			state->enemy.eposx ++;
		else
			state->enemy.direction = 1;
	}
	else if (state->enemy.direction == 1)
	{
		if (get_map(state->enemy.eposx - 1, state->enemy.eposy, state) != wall)
			state->enemy.eposx --;
		else
			state->enemy.direction = 0;
	}
}

void	game_over(t_state *s)
{
	if (s->posx == s->enemy.eposx && s->posy == s->enemy.eposy)
		exit_hook(s);
}
