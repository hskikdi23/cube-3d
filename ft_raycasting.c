/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:47:07 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:49:51 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reset_ray2(t_info *info)
{
	if (info->r.raydiry == 0)
		info->r.deltadistx = 0;
	else if (info->r.raydirx == 0)
		info->r.deltadistx = 1;
	else
		info->r.deltadistx = sqrt(1 + (info->r.raydiry
					* info->r.raydiry) / (info->r.raydirx
					* info->r.raydirx));
	if (info->r.raydirx == 0)
		info->r.deltadisty = 0;
	else if (info->r.raydiry == 0)
		info->r.deltadisty = 1;
	else
		info->r.deltadisty = sqrt(1 + (info->r.raydirx * \
					info->r.raydirx) / (info->r.raydiry * \
					info->r.raydiry));
}

void	ft_reset_ray(t_info *info)
{
	info->r.hit = 0;
	info->r.perpwalldist = 0;
	info->r.camerax = 2 * info->r.x / (double)RX - 1;
	info->r.raydirx = info->r.dirx + info->r.planx * info->r.camerax;
	info->r.raydiry = info->r.diry + info->r.plany * info->r.camerax;
	info->r.mapx = (int)info->r.posx;
	info->r.mapy = (int)info->r.posy;
	info->r.move_speed = 0.1;
	info->r.rot_speed = 0.033 * 1.8;
	ft_reset_ray2(info);
}

int	ft_raycasting(t_info *info)
{
	info->r.x = 0;
	while (info->r.x < RX)
	{
		ft_reset_ray(info);
		ft_calculs_ray(info);
		ft_color_stripe(info);
		info->r.x++;
	}
	mlx_put_image_to_window(info->data.mlx_ptr, info->data.mlx_win,
		info->data.img, 0, 0);
	ft_handle_move(info);
	return (0);
}
