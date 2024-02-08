/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:26:15 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:26:17 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_info(int fd, t_info *info, int gnl)
{
	char	*str;

	while (gnl)
	{
		gnl = get_next_line(fd, &str);
		if (gnl == -1)
		{
			free(info);
			ft_error("The file can't be opened");
		}
		if (!info->reading_map)
			parse_line(str, info);
		else
			copy_map(str, info);
		free(str);
		display_error(info);
	}
}

void	file_reader(char *file, t_info *info)
{
	int		fd;
	int		gnl;

	gnl = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(info);
		ft_error("The file can't be opened");
	}
	ft_get_info(fd, info, gnl);
	close(fd);
	display_error(info);
	ft_check_map(info->map, info);
	display_error(info);
}
