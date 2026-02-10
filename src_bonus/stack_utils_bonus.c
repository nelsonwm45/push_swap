/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:44:39 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 17:35:59 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

/* to find the stack len */
int	stack_len(t_stacks *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/* find the last node in stack */
t_stacks	*find_last(t_stacks *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* to determine whether the whole stack is sorted */
int	stack_sorted(t_stacks **stack)
{
	t_stacks	*node;

	node = *stack;
	while (node && node->next != NULL)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

/* find the min index node across the stack */
t_stacks	*find_min(t_stacks *stack)
{
	long		min_index;
	t_stacks	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	min_index = stack->index;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/* find the max index node across the stack */
t_stacks	*find_max(t_stacks *stack)
{
	long		max_index;
	t_stacks	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_index = stack->index;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
