/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:37:37 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 16:10:47 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	functions that swaps 1st node and 2nd node
*/
void	swap(t_stacks **stack)
{
	t_stacks	*first_node;
	t_stacks	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	second_node->prev = NULL;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	*stack = second_node;
}

void	sa(t_stacks **a, int print)
{
	swap(a);
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_stacks **b, int print)
{
	swap(b);
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_stacks **a, t_stacks **b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		ft_printf("ss\n");
}
