/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:02 by nchok             #+#    #+#             */
/*   Updated: 2024/05/23 16:19:45 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

/*
	Push from src to dest
	(1) detach a node from src (break the link)
	(2) push a node to dest (reconstruct the link)
*/
void	push(t_stacks **dest, t_stacks **src)
{
	t_stacks	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stacks **a, t_stacks **b, int print)
{
	push(a, b);
	if (print == 1)
		ft_printf("pa\n");
}

void	pb(t_stacks **a, t_stacks **b, int print)
{
	push(b, a);
	if (print == 1)
		ft_printf("pb\n");
}
