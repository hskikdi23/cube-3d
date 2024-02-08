/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:06:37 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/12 10:27:10 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_next(t_info *info)
{
	info->text[0].img = NULL;
	info->text[1].img = NULL;
	info->text[2].img = NULL;
	info->text[3].img = NULL;
	info->data.forward = 0;
	info->data.back = 0;
	info->data.left = 0;
	info->data.right = 0;
	info->data.rotate_left = 0;
	info->data.rotate_right = 0;
	info->r.posx = (double)info->dx + 0.5;
	info->r.posy = (double)info->dy + 0.5;
	info->r.dirx = 0;
	info->r.diry = 0;
	info->r.planx = 0;
	info->r.plany = 0;
}

void	ft_get_pos_player(t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (info->map[y])
	{
		while (info->map[y][x])
		{
			if (is_inset("NSEW", info->map[y][x]))
			{
				info->dx = y;
				info->dy = x;
				info->start = info->map[y][x];
				info->map[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_init_dirplayer(t_info *info)
{
	if (info->start == 'N')
		info->r.dirx = -1;
	if (info->start == 'S')
		info->r.dirx = 1;
	if (info->start == 'E')
		info->r.diry = 1;
	if (info->start == 'W')
		info->r.diry = -1;
	if (info->start == 'N')
		info->r.plany = 0.66;
	if (info->start == 'S')
		info->r.plany = -0.66;
	if (info->start == 'E')
		info->r.planx = 0.66;
	if (info->start == 'W')
		info->r.planx = -0.66;
}

void	ft_init(t_info **info)
{
	t_info	*ret;

	ret = malloc(sizeof(t_info));
	if (!ret)
		ft_error("malloc failed");
	ret->c = -1;
	ret->f = -1;
	ret->no = NULL;
	ret->so = NULL;
	ret->we = NULL;
	ret->ea = NULL;
	ret->msg_error = NULL;
	ret->size_line = 0;
	ret->nb_lines = 0;
	ret->map = NULL;
	ret->error = 0;
	ret->reading_map = 0;
	*info = ret;
}

int	ft_init_map(char *line, t_info *info)
{
	if (!ft_empty_line(line) && !info->reading_map)
		copy_map(line, info);
	return (1);
}
