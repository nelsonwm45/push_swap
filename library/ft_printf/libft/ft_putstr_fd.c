/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:42:36 by nchok             #+#    #+#             */
/*   Updated: 2023/10/30 16:17:05 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main(void)
// {
// 	ft_putstr_fd("lorem ipsum dolor sit amet", 2);
// 	write (2, "\n", 1);
// 	ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
// 	write (1, "\n", 1);
// 	ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
// 	write (1, "\n", 1);
// 	return (0);
// }
