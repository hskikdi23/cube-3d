/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:16:22 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 21:54:12 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s && s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if ((int)len < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s && i < len && start < (unsigned int)ft_strlen(s) && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)(malloc(sizeof(char) * (ft_strlen(src) + 1)));
	if (!dst)
		return (NULL);
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_strspush(char **str, char *push)
{
	char			*n_str;
	unsigned int	strlen;
	unsigned int	pushlen;

	strlen = gnl_strlen(*str);
	pushlen = gnl_strlen(push);
	if (strlen / 32 == (strlen + pushlen) / 32 && strlen)
		n_str = *str;
	else
		n_str = malloc(sizeof(char) * (strlen + pushlen \
					+ 32 - (strlen + pushlen) % 32 + 1));
	if (!n_str)
		return ;
	n_str[strlen + pushlen] = '\0';
	while (pushlen--)
		n_str[strlen + pushlen] = push[pushlen];
	if (n_str == *str)
		return ;
	while (strlen--)
		n_str[strlen] = (*str)[strlen];
	free(*str);
	*str = n_str;
}
