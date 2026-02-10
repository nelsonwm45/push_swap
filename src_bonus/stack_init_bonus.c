/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:11:08 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:58:30 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

long	ft_atol(const char *s)
{
	long	results;
	int		sign;

	results = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 7 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		results *= 10;
		results += (*s - '0');
		s++;
	}
	return (results * sign);
}

void	append_node(t_stacks **stack, int n)
{
	t_stacks	*node;
	t_stacks	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stacks));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->index = -1;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	*get_next_min(t_stacks **a)
{
	t_stacks	*min_node;
	t_stacks	*moving_node;
	int			min_found;

	min_node = NULL;
	min_found = 0;
	moving_node = *a;
	while (moving_node)
	{
		if ((moving_node->index == -1) && (min_found == 0
				|| moving_node->nbr < min_node->nbr))
		{
			min_node = moving_node;
			min_found = 1;
		}
		moving_node = moving_node->next;
	}
	return (min_node);
}

void	index_stack(t_stacks **a)
{
	t_stacks	*current_min_node;
	int			index;

	index = 0;
	current_min_node = get_next_min(a);
	while (current_min_node)
	{
		current_min_node->index = index++;
		current_min_node = get_next_min(a);
	}
}

/*
	check for syntax error, integer overflow, duplicates
	if no errors, append av to a
*/
void	init_stack_a(t_stacks **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_print_errors(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_print_errors(a);
		if (error_duplicate(*a, (int)n))
			free_print_errors(a);
		append_node(a, (int)n);
		i++;
	}
	index_stack(a);
}
