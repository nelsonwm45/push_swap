/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:39:26 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:56:09 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_current_line(char *store)
{
	int		i;
	char	*str;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] != '\0' && store[i] != '\n')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	i = -1;
	while (store[++i] != '\0' && store[i] != '\n')
		str[i] = store[i];
	if (store[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*store_next_line(char *store)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (store[i] != '\0' && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	str = ft_calloc((wordlen(store) - i + 1), sizeof(char));
	i++;
	while (store[i])
		str[j++] = store[i++];
	free(store);
	return (str);
}

char	*ft_readtostore(char *store, int fd)
{
	char	*buff;
	int		read_byte;

	if (!store)
		store = ft_calloc(1, 1);
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_byte = 1;
	while (!findchr(buff, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byte] = '\0';
		store = joinstr(store, buff);
	}
	free(buff);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*c_line;
	static char	*store[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	store[fd] = ft_readtostore(store[fd], fd);
	if (!store[fd])
		return (NULL);
	c_line = get_current_line(store[fd]);
	store[fd] = store_next_line(store[fd]);
	return (c_line);
}
