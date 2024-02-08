/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:48:26 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:52:10 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_right(t_info *info)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = info->r.planx;
	olddirx = info->r.dirx;
	if (info->data.rotate_right)
	{
		info->r.dirx = info->r.dirx * cos(-info->r.rot_speed / 2) - \
				info->r.diry * sin(-info->r.rot_speed / 2);
		info->r.diry = olddirx * sin(-info->r.rot_speed / 2) + \
				info->r.diry * cos(-info->r.rot_speed / 2);
		info->r.planx = info->r.planx * cos(-info->r.rot_speed / 2)
			- info->r.plany * sin(-info->r.rot_speed / 2);
		info->r.plany = oldplanx * sin(-info->r.rot_speed / 2) + \
				info->r.plany * cos(-info->r.rot_speed / 2);
	}
}

void	ft_rotate_left(t_info *info)
{
	double		oldplanx;
	double		olddirx;

	if (info->data.rotate_left)
	{
		olddirx = info->r.dirx;
		oldplanx = info->r.planx;
		info->r.dirx = info->r.dirx * cos(info->r.rot_speed / 2) - \
				info->r.diry * sin(info->r.rot_speed / 2);
		info->r.diry = olddirx * sin(info->r.rot_speed / 2) + \
				info->r.diry * cos(info->r.rot_speed / 2);
		info->r.planx = info->r.planx * cos(info->r.rot_speed / 2) - \
				info->r.plany * sin(info->r.rot_speed / 2);
		info->r.plany = oldplanx * sin(info->r.rot_speed / 2) + \
				info->r.plany * cos(info->r.rot_speed / 2);
	}
}
