/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:09:48 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:03:40 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1

typedef struct s_gnl
{
	char	*line;
}					t_gnl;

t_gnl				*gnl(void);
int					get_next_line(const int fd, char **line);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
void				*ft_m(unsigned int nb_byte);
void				ft_strpush(char **astr, char c);
void				ft_strspush(char **astr, char *s);

#endif
