/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:40:43 by nchok             #+#    #+#             */
/*   Updated: 2024/05/22 20:01:35 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
// #include <fcntl.h>
// #include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_readtostore(char *store, int fd);
size_t	wordlen(char *s);
char	*findchr(char *s, int c);
char	*joinstr(char *store, char *temp_buffer);
char	*get_current_line(char *store);
char	*store_next_line(char *store);
void	*ft_memset(void *b, int c, size_t len);

#endif
