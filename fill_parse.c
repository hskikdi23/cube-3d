/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:27:14 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:31:44 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_texture2(char **tab, t_info *info)
{
	if (**tab == 'W')
	{
		if (info->we)
			return (parse_error("two WE	textures", info));
		info->we = ft_strdup(tab[1]);
		if (!info->we)
			return (parse_error("malloc error1", info));
	}
	if (**tab == 'E')
	{
		if (info->ea)
			return (parse_error("two EA textures", info));
		info->ea = ft_strdup(tab[1]);
		if (!info->ea)
			return (parse_error("malloc error2", info));
	}
}

void	fill_texture(char **tab, t_info *info)
{
	if (**tab == 'N')
	{
		if (info->no)
			return (parse_error("two NO textures", info));
		info->no = ft_strdup(tab[1]);
		if (!info->no)
			return (parse_error("malloc error3", info));
	}
	if (**tab == 'S')
	{
		if (info->so)
			return (parse_error("two SO textures", info));
		info->so = ft_strdup(tab[1]);
		if (!info->so)
			return (parse_error("malloc error4", info));
	}
	if (**tab == 'W' || **tab == 'E')
		fill_texture2(tab, info);
}

int	is_inset(char *s, char c)
{
	while (s && *s)
	{
		if (c == *s++)
			return (1);
	}
	return (0);
}

void	fill_color(int floor, char *s, t_info *info)
{
	char	**tab;
	int		color;

	tab = ft_split(s, ',');
	if (!tab)
		return (parse_error("error malloc", info));
	color = ft_atoi(tab[0]);
	color = (color << 8) + ft_atoi(tab[1]);
	color = (color << 8) + ft_atoi(tab[2]);
	if (!floor)
		info->f = color;
	else
		info->c = color;
	ft_arrfree(tab);
}

int	parse_and_fill_color(char **tab, t_info *info)
{
	if (tab_len(tab) != 2 || ft_strlen(*tab) != 1)
	{
		parse_error("probably wrong color line", info);
		return (1);
	}
	if (parse_color(tab[1], info))
	{
		return (1);
	}
	if (**tab == 'F')
		fill_color(0, tab[1], info);
	else
		fill_color(1, tab[1], info);
	return (0);
}
