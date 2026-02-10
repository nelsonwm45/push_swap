/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:00:58 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 16:09:50 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	A function that rotates stack from bottom to top
	last_node becomes first_node
*/
void	rev_rotate(t_stacks **stack)
{
	t_stacks	*last_node;
	t_stacks	*first_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = first_node;
	last_node->prev = NULL;
	first_node->prev = last_node;
	*stack = last_node;
}

void	rra(t_stacks **a, int print)
{
	rev_rotate(a);
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stacks **b, int print)
{
	rev_rotate(b);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stacks **a, t_stacks **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print == 1)
		ft_printf("rrr\n");
}
