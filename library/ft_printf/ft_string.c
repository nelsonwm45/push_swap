/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:35:40 by nchok             #+#    #+#             */
/*   Updated: 2023/11/16 16:47:43 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], counter);
		i++;
	}
}
