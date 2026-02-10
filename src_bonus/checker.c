/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:09 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:58:04 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

static void	free_and_print_error(t_stacks **a, t_stacks **b)
{
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	perform_ops(char *line, t_stacks **a, t_stacks **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else
		free_and_print_error(a, b);
	return (0);
}

void	print_checker_results(t_stacks **a, t_stacks **b)
{
	int	len;

	len = stack_len(*a);
	if (stack_sorted(a) == 1 && stack_len(*a) == len)
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

int	main(int ac, char **av)
{
	t_stacks	*a;
	t_stacks	*b;
	char		*line;
	char		**split;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	split = NULL;
	split = parsing(ac, av);
	init_stack_a(&a, split + 1);
	free_array(split);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		perform_ops(line, &a, &b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	print_checker_results(&a, &b);
	return (0);
}
