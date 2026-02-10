/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:57:05 by nchok             #+#    #+#             */
/*   Updated: 2023/11/01 17:08:40 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!new)
		return ;
	list = *lst;
	if (list == NULL)
	{
		*lst = new;
	}
	else
	{
		while (list)
		{
			if (list->next == NULL)
			{
				list->next = new;
				break ;
			}
			list = list->next;
		}
	}
}
