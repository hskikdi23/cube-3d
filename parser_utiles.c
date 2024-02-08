/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:39:08 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:40:28 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_error(char *msg, t_info *info)
{
	if (info->error)
		return ;
	info->error = 1;
	info->msg_error = ft_strdup(msg);
	if (!info->msg_error)
		ft_error("malloc error dans parse_error");
}

void	display_error(t_info *info)
{
	if (!info->error)
		return ;
	ft_putendl_fd("Error", 1);
	if (info->msg_error)
	{
		ft_putendl_fd(info->msg_error, 2);
	}
	free_all(info);
	free(info);
	exit(-1);
}

void	free_all(t_info *info)
{
	ft_strdel(&info->no);
	ft_strdel(&info->so);
	ft_strdel(&info->we);
	ft_strdel(&info->ea);
	ft_strdel(&info->msg_error);
	ft_arrfree(info->map);
}

void	ft_push_tab(char ***addr_map, char *line, t_info *info)
{
	char	**map;
	int		i;
	int		len;
	char	**old_map;

	old_map = *addr_map;
	len = tab_len(old_map);
	i = 0;
	map = (char **)malloc(sizeof(char *) * (len + 3));
	if (!map)
		return (parse_error("malloc push_tab failed", info));
	while (old_map && old_map[i])
	{
		map[i] = ft_strdup(old_map[i]);
		i++;
	}
	map[i] = ft_strdup(line);
	i++;
	map[i] = NULL;
	ft_arrfree(old_map);
	*addr_map = map;
}
