/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:19:30 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:20:07 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_space_line(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == ' ')
			s[i] = '1';
		i++;
	}
}

int	check_player_by_line(char *s)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (s && s[i])
	{
		if (is_inset("NSWE", s[i]))
			ret++;
		i++;
	}
	return (ret);
}

void	replace_space_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		replace_space_line(map[i]);
		i++;
	}
}

void	ft_get_nb_lines(char **map, t_info *info)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (map && map[i] && !ft_empty_line(map[i]))
	{
		i++;
		info->nb_lines++;
	}
	while (map && map[i] && ft_empty_line(map[i]) && ++k)
	{
		i++;
	}
	if (map[i])
		write(1, "test\n", 5);
	if (map[i])
		return (parse_error("empty_line in the map", info));
}

int	check_player_pos(char **map, t_info *info)
{
	int		player;

	player = 0;
	while (map && *map)
	{
		player += check_player_by_line(*map);
		map++;
	}
	if (player != 1)
	{
		if (player < 1)
			parse_error("player pos in the map missing", info);
		else
			parse_error("multiple players in the map", info);
		return (1);
	}
	return (0);
}
