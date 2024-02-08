/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:25:11 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:27:42 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_fwd(t_info *info)
{
	if (info->data.forward)
	{
		if (info->map[(int)(info->r.posx + (info->r.dirx * \
						info->r.move_speed * 2))][(int)info->r.posy] != '1')
			info->r.posx += info->r.dirx * info->r.move_speed;
		if (info->map[(int)(info->r.posx)][(int)(info->r.posy +
					(info->r.diry * info->r.move_speed * 2))] != '1')
			info->r.posy += info->r.diry * info->r.move_speed;
	}
}

void	ft_move_back(t_info *info)
{
	if (info->data.back)
	{
		if (info->map[(int)(info->r.posx - (info->r.dirx * \
						info->r.move_speed * 2))][(int)(info->r.posy)] != '1')
			info->r.posx -= info->r.dirx * info->r.move_speed;
		if (info->map[(int)(info->r.posx)][(int)(info->r.posy -
					(info->r.diry * info->r.move_speed * 2))] != '1')
			info->r.posy -= info->r.diry * info->r.move_speed;
	}
}

void	ft_move_left(t_info *info)
{
	if (info->data.left)
	{
		if (info->map[(int)(info->r.posx - info->r.diry * \
					(info->r.move_speed * 2))][(int)info->r.posy] != '1')
			info->r.posx -= info->r.diry * info->r.move_speed;
		if (info->map[(int)info->r.posx][(int)(info->r.posy + \
					info->r.dirx * (info->r.move_speed * 2))] != '1')
			info->r.posy += info->r.dirx * info->r.move_speed;
	}
}

void	ft_move_right(t_info *info)
{
	if (info->data.right)
	{
		if (info->map[(int)(info->r.posx + info->r.diry * \
					(info->r.move_speed * 2))][(int)info->r.posy] == '0')
			info->r.posx += info->r.diry * info->r.move_speed;
		if (info->map[(int)info->r.posx][(int)(info->r.posy - \
					info->r.dirx * (info->r.move_speed * 2))] == '0')
			info->r.posy -= info->r.dirx * info->r.move_speed;
	}
}

void	ft_handle_move(t_info *info)
{
	ft_move_right(info);
	ft_move_left(info);
	ft_move_fwd(info);
	ft_move_back(info);
	ft_rotate_right(info);
	ft_rotate_left(info);
}
