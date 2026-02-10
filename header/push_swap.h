/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:22:07 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:55:11 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/ft_printf/ft_printf.h"
# include "../library/ft_printf/get_next_line/get_next_line_bonus.h"
# include "../library/ft_printf/libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int				nbr;
	int				index;
	struct s_stacks	*prev;
	struct s_stacks	*next;
}					t_stacks;

// Stack Operations
// Push
void				push(t_stacks **dest, t_stacks **src);
void				pa(t_stacks **a, t_stacks **b, int print);
void				pb(t_stacks **a, t_stacks **b, int print);

// Reverse Rotate
void				rev_rotate(t_stacks **stack);
void				rra(t_stacks **a, int print);
void				rrb(t_stacks **b, int print);
void				rrr(t_stacks **a, t_stacks **b, int print);

// Rotate
void				rotate(t_stacks **stack);
void				ra(t_stacks **a, int print);
void				rb(t_stacks **b, int print);
void				rr(t_stacks **a, t_stacks **b, int print);

// Swap
void				swap(t_stacks **stack);
void				sa(t_stacks **a, int print);
void				sb(t_stacks **b, int print);
void				ss(t_stacks **a, t_stacks **b, int print);

// Parsing
int					error_syntax(char *str);
int					error_duplicate(t_stacks *a, int n);
void				arguement_check_man(int ac, char **av);
void				free_stack(t_stacks **stack);
void				free_print_errors(t_stacks **a);
char				**wordsplit(char *s, char c);
void				free_array(char **array);
char				**remodify_input(char **av);

// Stacks Initialisation
void				init_stack_a(t_stacks **a, char **av);
void				append_node(t_stacks **stack, int n);
void				index_stack(t_stacks **a);
void				*get_next_min(t_stacks **a);
long				ft_atol(const char *s);

// Stacks Utils
int					stack_len(t_stacks *stack);
t_stacks			*find_last(t_stacks *stack);
int					stack_sorted(t_stacks **stack);
int					get_distance(t_stacks **stack, int index);
int					get_min(t_stacks **stack, int value);
t_stacks			*find_min(t_stacks *stack);
t_stacks			*find_max(t_stacks *stack);

// Algorithms : Radixsort
void				radix_sort(t_stacks **a, t_stacks **b);
int					get_max_bits(t_stacks **a);

// Algorithms : Simplesort
void				simple_sort(t_stacks **a, t_stacks **b);
void				sort_three(t_stacks **a);
void				sort_four(t_stacks **a, t_stacks **b);
void				sort_five(t_stacks **a, t_stacks **b);

// Testing
void				print_stack(t_stacks **stack);
void				print_node(t_stacks **stack);

#endif
