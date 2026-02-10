/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:09 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 18:51:47 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*a;
	t_stacks	*b;
	char		**split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		arguement_check_man(ac, av);
	else
		split = remodify_input(av);
	init_stack_a(&a, split + 1);
	free_array(split);
	if (stack_sorted(&a) == 0)
	{
		if (stack_len(a) > 5)
			radix_sort(&a, &b);
		else
			simple_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
