/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:42:14 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:42:30 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_full(t_info *info)
{
	free_all(info);
}

int	ft_quit_game(t_info *info, char *msg)
{
	free_full(info);
	if (msg)
		ft_error(msg);
	exit(0);
	return (0);
}
