/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:07:54 by nchok             #+#    #+#             */
/*   Updated: 2024/05/27 15:07:47 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	find the distance of node to that index
*/
int	get_distance(t_stacks **stack, int index)
{
	t_stacks	*head;
	int			distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

/*
	looping thru the stack, find the min index
*/
int	get_min(t_stacks **stack, int value)
{
	t_stacks	*moving_node;
	int			min;

	moving_node = *stack;
	min = moving_node->index;
	while (moving_node->next)
	{
		moving_node = moving_node->next;
		if ((moving_node->index < min) && moving_node->index != value)
			min = moving_node->index;
	}
	return (min);
}

/*
	print node num, node nbr, node index
	for debugg purpose
*/
void	print_stack(t_stacks **stack)
{
	int			i;
	t_stacks	*head;

	i = 0;
	head = *stack;
	if (!head)
		ft_printf("Empty Stack\n");
	while (*stack != NULL)
	{
		ft_printf("Node[%i]\n", i++);
		ft_printf("nbr: %i\n", (*stack)->nbr);
		ft_printf("index: %i\n", (*stack)->index);
		*stack = (*stack)->next;
	}
	*stack = head;
}

/*
	print node
*/
void	print_node(t_stacks **stack)
{
	int			i;
	t_stacks	*head;

	i = 0;
	head = *stack;
	if (!head)
		ft_printf("Empty Node\n");
	ft_printf("Node[%i]\n", i++);
	ft_printf("nbr: %i\n", head->nbr);
	ft_printf("index: %i\n", head->index);
}

void	arguement_check_man(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	else if (ac == 2 && !av[1][0])
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}
