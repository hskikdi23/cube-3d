/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:36:56 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 22:07:07 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl(void)
{
	static t_gnl	gnl = {NULL};

	return (&gnl);
}

void	ft_free_and_replace(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*str)
		str++;
	ft_strspush(&tmp, str);
	free(gnl()->line);
	gnl()->line = tmp;
}

int	get_and_return(char *buff, char **line)
{
	char	*search;

	if (buff)
		ft_strspush(&(gnl()->line), buff);
	search = ft_strchr(gnl()->line, '\n');
	if (search)
	{
		*line = ft_substr(gnl()->line, 0, search - gnl()->line);
		ft_free_and_replace(search);
		return (1);
	}
	if (!buff)
	{
		*line = ft_strdup(gnl()->line);
		free(gnl()->line);
		gnl()->line = NULL;
		return (0);
	}
	if (gnl()->line)
		*line = gnl()->line;
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1];
	int				k;
	int				ret;
	char			*search;

	if (fd == -1 || BUFFER_SIZE < 1 || !line)
		return (-1);
	search = ft_strchr(gnl()->line, '\n');
	if (search)
		return (get_and_return(NULL, line));
	k = read(fd, buff, BUFFER_SIZE);
	while (k)
	{
		if (k > 0)
		{
			buff[k] = (char)0;
			ret = get_and_return(buff, line);
			if (ret)
				return (ret);
		}
		else
			return (-1);
		k = read(fd, buff, BUFFER_SIZE);
	}
	return (get_and_return(NULL, line));
}
