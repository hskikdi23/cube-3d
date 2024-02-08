/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:17:37 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:17:39 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_zero(char **map, int y, int x)
{
	if (y > 0 && x && x < ft_strlen(map[y - 1]) \
		&& map[y + 1] && x < ft_strlen(map[y + 1]) && x < ft_strlen(map[y]) - 1)
	{
		return (0);
	}
	return (1);
}

int	ft_check_walls(char **map, t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	while (map[++y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' && check_zero(map, y, x))
			{
				parse_error("map walls probleme, '0' at the bordure", info);
				return (1);
			}
			x++;
		}
		x = 0;
	}
	return (0);
}

int	ft_check_empty_line(char **map, t_info *info)
{
	int		i;

	i = -1;
	ft_get_nb_lines(map, info);
	display_error(info);
	while (map && map[++i] && i < info->nb_lines)
	{
		if (ft_empty_line(map[i]))
			return (1);
	}
	return (0);
}

void	ft_check_map(char **map, t_info *info)
{
	if (!map || !*map)
		return (parse_error("no map detected", info));
	if (check_player_pos(map, info))
		display_error(info);
	ft_get_pos_player(info);
	if (ft_check_walls(map, info))
		display_error(info);
	if (ft_check_empty_line(map, info))
		display_error(info);
	replace_space_map(info->map);
	ft_extend_map(map, info);
	display_error(info);
}
