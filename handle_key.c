/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:58:11 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/12 10:39:25 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_cross(t_info *info)
{
	ft_quit_game(info, NULL);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == 53)
		ft_quit_game(info, NULL);
	if (key == FORWARD_ZW)
		info->data.forward = 1;
	else if (key == BACK_S)
		info->data.back = 1;
	else if (key == LEFT_AQ)
		info->data.left = 1;
	else if (key == RIGHT_D)
		info->data.right = 1;
	else if (key == L_ARROW)
		info->data.rotate_left = 1;
	else if (key == R_ARROW)
		info->data.rotate_right = 1;
	return (1);
}

int	key_release(int key, t_info *info)
{
	if (key == FORWARD_ZW)
		info->data.forward = 0;
	if (key == BACK_S)
		info->data.back = 0;
	if (key == LEFT_AQ)
		info->data.left = 0;
	if (key == RIGHT_D)
		info->data.right = 0;
	if (key == L_ARROW)
		info->data.rotate_left = 0;
	if (key == R_ARROW)
		info->data.rotate_right = 0;
	return (1);
}

void	ft_hook(t_info *info)
{
	mlx_hook(info->data.mlx_win, 17, 0, close_cross, info);
	mlx_hook(info->data.mlx_win, 2, 1L << 0, key_press, info);
	mlx_loop_hook(info->data.mlx_ptr, ft_raycasting, info);
	mlx_hook(info->data.mlx_win, 3, 1L << 1, key_release, info);
	mlx_loop(info->data.mlx_ptr);
}

void	ft_start_game(t_info *info)
{
	if (!info->map)
		ft_quit_game(info, "map probleme");
	info->data.mlx_ptr = mlx_init();
	if (!info->data.mlx_ptr)
		ft_quit_game(info, "mlx_init error");
	ft_init_next(info);
	ft_init_dirplayer(info);
	ft_init_text(info);
	info->data.img = mlx_new_image(info->data.mlx_ptr, RX, RY);
	info->data.addr = (int *)mlx_get_data_addr(info->data.img, &info->data.bpp,
			&info->data.lline, &info->data.endian);
	info->data.mlx_win = mlx_new_window(info->data.mlx_ptr, RX,
			RY, "Cub3d");
	ft_hook(info);
}
