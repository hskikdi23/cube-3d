/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:29:17 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:31:50 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tab_len(char **tab)
{
	int		ret;

	ret = 0;
	while (tab && *tab)
	{
		tab++;
		ret++;
	}
	return (ret);
}

void	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(-1);
}

void	parse_extension(char *file)
{
	int		i;

	i = 0;
	while (file[i] && file[i + 1])
		i++;
	if (i < 3 || file[i] != 'b')
		ft_error("the map must be a .cub");
	if (--i && file[i] != 'u')
		ft_error("the map must be a .cub");
	if (--i && file[i] != 'c')
		ft_error("the map must be a .cub");
	if (--i && file[i] != '.')
		ft_error("the map must be a .cub");
}

int	parse_line(char *str, t_info *info)
{
	char	**tab;

	if (!*str || (ft_empty_line(str) && !info->reading_map))
		return (1);
	if (is_inset(" 10", *str))
		return (ft_init_map(str, info));
	if (!is_inset("NOSWAEFC", *str))
	{
		parse_error("Wrong first char in an elem", info);
		return (1);
	}
	if (is_inset("FC", *str))
		return (handle_color(str, info));
	tab = ft_split(str, ' ');
	if (tab && *tab && is_inset("NOSWAE", **tab))
		fill_texture(tab, info);
	ft_arrfree(tab);
	return (1);
}
