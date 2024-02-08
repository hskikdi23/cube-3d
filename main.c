/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:22:45 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:40:10 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_info	*info;

	info = NULL;
	if (ac != 2)
	{
		ft_error("usage : one argument expected");
	}
	parse_extension(av[1]);
	ft_init(&info);
	file_reader(av[1], info);
	ft_start_game(info);
	return (0);
}
