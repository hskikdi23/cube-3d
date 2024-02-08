/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:25:33 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:25:40 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_sizeline(char **map, t_info *info)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		if (ft_strlen(map[i]) > info->size_line)
		info->size_line = ft_strlen(map[i]);
		i++;
	}
	if (!info->size_line)
		return (parse_error("map seems empty", info));
	display_error(info);
}

char	*ft_extend_line(char *line, t_info *info)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (info->size_line + 1));
	if (!ret)
	{
		parse_error("malloc error extend line", info);
		return (ret);
	}
	while (line && line[i])
	{
		ret[i] = line[i];
		i++;
	}
	while (i < info->size_line)
	{
		ret[i] = '1';
		i++;
	}
	ret[i] = (char)0;
	return (ret);
}

void	ft_extend_map(char **map, t_info *info)
{
	char	**new;
	int		i;

	i = 0;
	ft_get_sizeline(map, info);
	new = malloc(sizeof(char *) * (info->nb_lines + 1));
	if (!new)
		return (parse_error("malloc failed extendmap", info));
	while (map[i] && i < info->nb_lines)
	{
		new[i] = ft_extend_line(map[i], info);
		i++;
	}
	new[i] = NULL;
	ft_arrfree(info->map);
	info->map = NULL;
	info->map = new;
}
