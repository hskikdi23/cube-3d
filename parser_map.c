/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:33:41 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:36:22 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_struct(t_info *info)
{
	if (info->error)
		return (1);
	if (info->c == -1 || info->f == -1 || !info->no)
	{
		parse_error("missing elements before the map", info);
		return (1);
	}
	if (!info->so || !info->we || !info->we || !info->ea)
	{
		parse_error("missing elements before map", info);
		return (1);
	}
	return (0);
}

int	ft_empty_line(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] == ' ' || s[i] == '\v' || s[i] == '\t' || \
			s[i] == '\f')
	{
		i++;
	}
	if (i == ft_strlen(s) || !ft_strlen(s))
		return (1);
	return (0);
}

int	check_line_map(char *str, t_info *info)
{
	while (str && *str)
	{
		if (!is_inset("01 NSEW", *str))
		{
			parse_error("wrong char in the map", info);
			return (1);
		}
		str++;
	}
	return (0);
}

void	copy_map(char *line, t_info *info)
{
	if (check_struct(info) || check_line_map(line, info))
		return ;
	info->reading_map = 1;
	ft_push_tab(&(info->map), line, info);
}
