/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:39:06 by nchok             #+#    #+#             */
/*   Updated: 2024/05/22 20:12:14 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	wordlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*findchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*joinstr(char *store, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!store || !buff)
		return (NULL);
	str = ft_calloc((wordlen(store) + wordlen(buff) + 1), sizeof(char));
	i = -1;
	while (store[++i])
		str[i] = store[i];
	j = -1;
	while (buff[++j])
		str[i + j] = buff[j];
	free(store);
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
