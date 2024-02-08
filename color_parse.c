/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:21:58 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:23:39 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_numeric(char *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] && is_inset("\v\t\f\n ", s[i]))
		i++;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		k++;
		i++;
	}
	while (s[i] && is_inset("\v\t\f\n ", s[i]))
		i++;
	if (k && !s[i])
		return (k);
	return (0);
}

int	check_comas(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (0);
	return (1);
}

void	check_numeric(char **tab, t_info *info)
{
	int		k;
	int		nb;

	k = 0;
	nb = 0;
	while (tab && *tab)
	{
		k = parse_numeric(*tab);
		nb = ft_atoi(*tab);
		if ((k < 1 || k > 3) || (nb > 255 || nb < 0))
			return (parse_error("r g and b must be between 0 and 255", info));
		tab++;
	}
}

int	parse_color(char *str, t_info *info)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
	{
		parse_error("malloc error", info);
		return (1);
	}
	if (tab_len(tab) != 3 || check_comas(str))
	{
		parse_error("wrong format of color", info);
		ft_arrfree(tab);
		return (-1);
	}
	check_numeric(tab, info);
	ft_arrfree(tab);
	return (0);
}

int	handle_color(char *str, t_info *info)
{
	char	**tab;
	int		i;

	i = 1;
	while (str[i] && (str[i] == '\v' || str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[1] != ' ' || !str[i])
	{
		parse_error("wrong element", info);
		return (1);
	}
	tab = malloc(sizeof(char *) * 3);
	if (!tab)
		ft_error("malloc error");
	if (*str == 'F')
		tab[0] = ft_strdup("F");
	else
		tab[0] = ft_strdup("C");
	tab[1] = ft_strdup(str + i);
	tab[2] = NULL;
	i = 0;
	parse_and_fill_color(tab, info);
	ft_arrfree(tab);
	return (1);
}
