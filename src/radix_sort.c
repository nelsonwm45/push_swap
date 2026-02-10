/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:52:58 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 16:12:07 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	to get max bits of nbr;
*/
int	get_max_bits(t_stacks **a)
{
	t_stacks	*moving_node;
	int			max_index;
	int			max_bits;

	moving_node = *a;
	max_index = moving_node->index;
	max_bits = 0;
	while (moving_node)
	{
		if (moving_node->index > max_index)
			max_index = moving_node->index;
		moving_node = moving_node->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stacks **a, t_stacks **b)
{
	t_stacks	*node;
	int			len;
	int			max_bits;
	int			i;
	int			j;

	node = *a;
	len = stack_len(node);
	i = 0;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < len)
		{
			node = *a;
			if (((node->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
		}
		while (stack_len(*b) != 0)
			pa(a, b, 1);
		i++;
	}
}
