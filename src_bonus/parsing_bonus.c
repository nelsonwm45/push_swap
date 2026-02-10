/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:02:27 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:58:12 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

char	**parsing(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
		arguement_check(ac, av);
	else
		av = remodify_input(av);
	return (av);
}
