/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safamran <safamran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:02:29 by safamran          #+#    #+#             */
/*   Updated: 2025/03/19 12:06:28 by safamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countword(char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			n++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (n);
}

void	megafree(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

char	*allouee(char *str, char c)
{
	int		i;
	int		j;
	char	*mot;

	i = 0;
	j = 0;
	while (str[j] != '\0' && str[j] != c)
		j++;
	mot = (char *)malloc(sizeof(char) * (j + 1));
	if (mot == 0)
		return (NULL);
	while (i < j)
	{
		mot[i] = str[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

char	**my_split(char const *s, char c)
{
	char	**tab;
	int		x;
	int		y;

	y = 0;
	x = countword((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (x + 1));
	if (tab == 0 || s == 0)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			tab[y] = allouee((char *)s, c);
			if (tab[y] == NULL)
				return (megafree(tab, y), NULL);
			y++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	tab[y] = 0;
	return (tab);
}
/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		ft_putchar(str[c]);
	c++;
	}
}

int	main(void)
{
	char c = ' ';
	char *test  = "couiii i i  coui couui coui";
	char **tabmega;

	tabmega = ft_split(test, c);
	int i = 0;
	while (i < 6)
	{
		printf("%s\n", tabmega[i]);
	i++;
	}
	megafree(tabmega, 6);
return (0);
}*/
