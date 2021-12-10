/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:46:39 by snadji-h          #+#    #+#             */
/*   Updated: 2021/12/08 21:02:34 by snadji-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	i = 0;
	while (s1[len] != 0)
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == 0)
		return (0);
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

static void	ft_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

static char	*ft_str(int i, char *str, int n)
{
	char	*dest;
	int		j;

	dest = malloc(i + n + 1);
	if (dest == 0)
		return (0);
	j = 0;
	if (n)
	{
		dest[0] = '-';
		j++;
	}
	while (i > 0)
	{
		dest[j] = str[i - 1];
		i--;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	int		i;
	int		negative;
	char	str [40];

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ft_isnegative(&n, &negative);
	while (n)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = 0;
	return (ft_str(i, str, negative));
}
