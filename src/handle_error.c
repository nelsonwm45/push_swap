/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:10:35 by nchok             #+#    #+#             */
/*   Updated: 2024/05/22 20:04:21 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	A function to handle correct syntax are received for all numbers
	E.g: +12, -12, 12
	Return (1) if errors happen
	1) First letter is not sign/digits
	2) First letter is sign but next letter not number
	3) Check the remaining letter if they are digits
*/
int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0'
			&& str[i + 1] <= '9'))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
	check if the nbr passed in already existed in stack
	return (1) : there is existed number in stack
	return (0) : no existed number in stack
*/
int	error_duplicate(t_stacks *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
	Function to free stack if there are errors
	Free every nodes in stack
*/
void	free_stack(t_stacks **stack)
{
	t_stacks	*next;
	t_stacks	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array[i])
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_print_errors(t_stacks **a)
{
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}
