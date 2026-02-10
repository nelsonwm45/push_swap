/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:04:02 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:57:02 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	sort three algorithms :
	make the largest node at the bottom
	sort the first and second node
*/
void	sort_three(t_stacks **a)
{
	t_stacks	*largest_node;
	t_stacks	*first_node;
	t_stacks	*second_node;

	first_node = *a;
	second_node = (*a)->next;
	largest_node = find_max(*a);
	if (first_node == largest_node)
		ra(a, 1);
	else if (second_node == largest_node)
		rra(a, 1);
	first_node = *a;
	second_node = (*a)->next;
	if (first_node->index > second_node->index)
		sa(a, 1);
}

void	sort_four(t_stacks **a, t_stacks **b)
{
	int	distance;

	if (stack_sorted(a) == 1)
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
		rra(a, 1);
	if (stack_sorted(a) == 1)
		return ;
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stacks **a, t_stacks **b)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (distance == 4)
		rra(a, 1);
	if (stack_sorted(a) == 1)
		return ;
	pb(a, b, 1);
	sort_four(a, b);
	pa(a, b, 1);
}

void	simple_sort(t_stacks **a, t_stacks **b)
{
	int	len;

	if (stack_len(*a) == 0 || stack_len(*a) == 1 || stack_sorted(a) != 0)
		return ;
	len = stack_len(*a);
	if (len == 2)
		sa(a, 1);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
}
