/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:01:36 by snadji-h          #+#    #+#             */
/*   Updated: 2021/11/30 21:49:37 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H



# define KEY_EXIT 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0



typedef enum e_obj
{
	wall,
	start,
	floor,
	object,
	finish
} t_obj;

typedef struct s_map
{
	int		width;
	int		height;
	t_obj	*tab;
} t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*image;
}	t_image;

typedef struct s_state
{
	int		posx;
	int		posy;
	void	*mlx;
	void	*win;
	t_image	player;
	t_image	wall;
	t_image	object;
	t_image	finish;
	t_image	floor;
	t_map	map;
}	t_state;

#endif
