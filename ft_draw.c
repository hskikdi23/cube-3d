/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:43:08 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:43:13 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reset_texture(t_info *info)
{
	if (info->r.side == 0 && info->r.raydirx < 0)
		info->t.texdir = 0;
	if (info->r.side == 0 && info->r.raydirx >= 0)
		info->t.texdir = 1;
	if (info->r.side == 1 && info->r.raydiry < 0)
		info->t.texdir = 2;
	if (info->r.side == 1 && info->r.raydiry >= 0)
		info->t.texdir = 3;
	if (info->r.side == 0)
		info->t.wallx = info->r.posy + info->r.perpwalldist \
						* info->r.raydiry;
	else
		info->t.wallx = info->r.posx + info->r.perpwalldist \
						* info->r.raydirx;
	info->t.wallx -= floor((info->t.wallx));
}

void	ft_draw_texture(t_info *info, int x, int y)
{
	(void)x;
	y = info->r.drawstart - 1;
	ft_reset_texture(info);
	info->t.step = 1.0 * info->text[0].height / info->r.lineheight;
	info->t.texx = (int)(info->t.wallx * \
			(double)info->text[info->t.texdir].width);
	if (info->r.side == 0 && info->r.raydirx > 0)
		info->t.texx = info->text[info->t.texdir].width - \
		info->t.texx - 1;
	if (info->r.side == 1 && info->r.raydiry < 0)
		info->t.texx = info->text[info->t.texdir].width - \
		info->t.texx - 1;
	info->t.texpos = (info->r.drawstart - RY / 2 + \
	info->r.lineheight / 2) * info->t.step;
	while (++y < info->r.drawend)
	{
		info->t.texy = (int)info->t.texpos & \
		(info->text[info->t.texdir].height - 1);
		info->t.texpos += info->t.step;
		if (y < RY && x < RX)
			info->data.addr[y * info->data.lline / 4 + x] = \
			info->text[info->t.texdir].addr[info->t.texy * \
			info->text[info->t.texdir].lline / \
			4 + info->t.texx];
	}
}

void	ft_color_stripe(t_info *info)
{
	int		j;
	int		i;

	j = -1;
	info->r.drawend = RY - info->r.drawstart;
	i = info->r.drawend;
	while (++j < info->r.drawstart)
		info->data.addr[j * info->data.lline / 4 + \
		info->r.x] = info->c;
	if (j <= info->r.drawend)
		ft_draw_texture(info, info->r.x, j);
	j = i;
	while (++j < RY)
		info->data.addr[j * info->data.lline / 4 + \
		info->r.x] = info->f;
}
