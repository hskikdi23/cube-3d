/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:38:43 by mkayumba          #+#    #+#             */
/*   Updated: 2021/08/17 19:42:46 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	char	**ft_free(char **tab, int i)
{
	while (--i >= 0)
	{
		free(tab[i]);
		tab[i] = 0;
	}
	free(tab);
	tab = 0;
	return (0);
}

static	int	nb_word(char *s, char c)
{
	int	line;

	line = 0;
	while (s && *s && *s == c)
		s++;
	if (s && *s && *s != c)
		line++;
	while (s && *s && *s != c)
		s++;
	if (s && *s && *s == c)
		line += nb_word(s, c);
	return (line);
}

static	int	nb_char(char *s, char c)
{
	int	nbr_char;

	nbr_char = 0;
	while (s && s[nbr_char] && s[nbr_char] != c)
		nbr_char++;
	return (nbr_char);
}

static char	*boucle(char *tab, char *s, char c)
{
	int	j;

	j = 0;
	while (*s && *s != c)
	{
		tab[j] = *s;
		j++;
		s++;
	}
	tab[j] = '\0';
	return (s);
}

char	**ft_split(char *s, char c)
{
	int		nb_w;
	int		i;
	char	**tab;

	i = -1;
	nb_w = nb_word(s, c);
	tab = malloc(sizeof(char *) * (nb_w + 1));
	if (!tab || !s)
		return (0);
	while (++i < nb_w)
	{
		while (*s == c)
			s++;
		tab[i] = malloc(sizeof(char) * (nb_char(s, c) + 1));
		if (!tab)
			return (ft_free(tab, i));
		s = boucle(tab[i], s, c);
	}
	tab[i] = 0;
	return (tab);
}
