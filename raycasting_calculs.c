/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:44:20 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:46:16 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_step(t_info *info)
{
	if (info->r.raydirx < 0)
	{
		info->r.stepx = -1;
		info->r.sidedistx = (info->r.posx - info->r.mapx) \
							* info->r.deltadistx;
	}
	else
	{
		info->r.stepx = 1;
		info->r.sidedistx = (info->r.mapx + 1.0 - info->r.posx) \
							* info->r.deltadistx;
	}
	if (info->r.raydiry < 0)
	{
		info->r.stepy = -1;
		info->r.sidedisty = (info->r.posy - info->r.mapy) \
							* info->r.deltadisty;
	}
	else
	{
		info->r.stepy = 1;
		info->r.sidedisty = (info->r.mapy + 1.0 - info->r.posy) \
							* info->r.deltadisty;
	}
}

void	ft_search_wall(t_info *info)
{
	while (info->r.hit == 0)
	{
		if (info->r.sidedistx < info->r.sidedisty)
		{
			info->r.sidedistx += info->r.deltadistx;
			info->r.mapx += info->r.stepx;
			info->r.side = 0;
		}
		else
		{
			info->r.sidedisty += info->r.deltadisty;
			info->r.mapy += info->r.stepy;
			info->r.side = 1;
		}
		if (info->map[info->r.mapx][info->r.mapy] == '1')
			info->r.hit = 1;
	}
}

void	ft_calcul_drawstartend(t_info *info)
{
	if (info->r.side == 0)
		info->r.perpwalldist = ((double)info->r.mapx - info->r.posx + \
				(1 - (double)info->r.stepx) / 2) / info->r.raydirx;
	else
		info->r.perpwalldist = ((double)info->r.mapy - \
				info->r.posy + (1 - (double)info->r.stepy) / 2) / \
				info->r.raydiry;
	info->r.lineheight = (int)(RY / info->r.perpwalldist);
	info->r.drawstart = -info->r.lineheight / 2 + RY / 2;
	if (info->r.drawstart < 0)
		info->r.drawstart = 0;
	info->r.drawend = info->r.lineheight / 2 + RY / 2;
	if (info->r.drawend >= RY || RY < 0)
		info->r.drawend = RY - 1;
}

void	ft_calculs_ray(t_info *info)
{
	ft_step(info);
	ft_search_wall(info);
	ft_calcul_drawstartend(info);
}
