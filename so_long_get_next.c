/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:45:07 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/08 10:53:27 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen2(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*join(char *str, char *buffer, int count)
{
	char	*mem;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = strlen2(str);
	mem = malloc(sizeof(char) * (len + count + 1));
	if (mem == 0)
		return (0);
	while (i < len)
	{
		mem[i] = str[i];
		i++;
	}
	while (j < count)
		mem[i++] = buffer[j++];
	mem[i] = 0;
	if (str)
		free (str);
	return (mem);
}

/*
 * charger la map par buffer avec le join /// 5 fonctio 
 */

char	*read_map(char *path)
{	
	char	*str;
	char	buffer[1000];
	int		count;
	int		fd;	

	count = 1;
	str = 0;
	fd = open(path, 0);
	while (count > 0)
	{
		count = read(fd, buffer, 1000);
		if (count > 0)
			str = join(str, buffer, count);
	}
	close(fd);
	return (str);
}
