/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:18:31 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:20:10 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_extension_xpm(char *file)
{
	int		i;

	i = 0;
	while (file[i] && file[i + 1])
		i++;
	if (i < 3 || file[i] != 'm')
		return (1);
	if (--i && file[i] != 'p')
		return (1);
	if (--i && file[i] != 'x')
		return (1);
	if (--i && file[i] != '.')
		return (1);
	return (0);
}

void	parse_texture_extension(t_info *info)
{
	if (parse_extension_xpm(info->no))
		ft_quit_game(info, "texture must be a xpm (no)");
	if (parse_extension_xpm(info->so))
		ft_quit_game(info, "texture must be a xpm (so)");
	if (parse_extension_xpm(info->ea))
		ft_quit_game(info, "texture must be a xpm (ea)");
	if (parse_extension_xpm(info->we))
		ft_quit_game(info, "texture must be a xpm (we)");
}

void	get_text_addr(t_info *info)
{
	info->text[0].addr = (int *)mlx_get_data_addr(info->text[0].img,
			&info->text[0].bpp, &info->text[0].lline, &info->text[0].endian);
	info->text[1].addr = (int *)mlx_get_data_addr(info->text[1].img,
			&info->text[1].bpp, &info->text[1].lline, &info->text[1].endian);
	info->text[2].addr = (int *)mlx_get_data_addr(info->text[2].img,
			&info->text[2].bpp, &info->text[2].lline, &info->text[2].endian);
	info->text[3].addr = (int *)mlx_get_data_addr(info->text[3].img,
			&info->text[3].bpp, &info->text[3].lline, &info->text[3].endian);
}

void	ft_init_text(t_info *info)
{
	parse_texture_extension(info);
	info->text[0].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
			info->no, &(info->text[0].width), &(info->text[0].height));
	if (!info->text[0].img)
		ft_quit_game(info, "Texture NO failed to load");
	info->text[1].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
			info->so, &(info->text[1].width), &(info->text[1].height));
	if (!info->text[1].img)
		ft_quit_game(info, "Texture SO failed to load");
	info->text[2].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
			info->we, &(info->text[2].width), &(info->text[2].height));
	if (!info->text[2].img)
		ft_quit_game(info, "Texture WE failed to load");
	info->text[3].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
			info->ea, &(info->text[3].width), &(info->text[3].height));
	if (!info->text[3].img)
		ft_quit_game(info, "Texture EA failed to load");
	get_text_addr(info);
}
