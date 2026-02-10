/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:03:34 by nchok             #+#    #+#             */
/*   Updated: 2024/05/27 15:08:34 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	print_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	arguement_check(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	else if (ac == 2 && !av[1][0])
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
