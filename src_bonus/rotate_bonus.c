/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:19:16 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 17:58:23 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

/*
	rotate the first_node from down to last_node
*/
void	rotate(t_stacks **stack)
{
	t_stacks	*last_node;
	t_stacks	*first_node;
	t_stacks	*second_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	last_node = find_last(*stack);
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	if (second_node)
		second_node->prev = NULL;
	*stack = second_node;
}

void	ra(t_stacks **a, int print)
{
	rotate(a);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_stacks **b, int print)
{
	rotate(b);
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_stacks **a, t_stacks **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		ft_printf("rr\n");
}
