/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:32 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 16:29:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

t_stack		*init_stack(void);
t_node		*new_node(int content);
void		push_top_stack(t_stack *stack, t_node *ph_node);
void		push_bottom_stack(t_stack *stack, t_node *ph_node);
t_node		*pop_top_stack(t_stack *stack);
t_node		*pop_bottom_stack(t_stack *stack);

void		print_error(int sign);

int			*arg_parsing(t_stack *stack, int ac, char *av[]);
int			*stack_to_arr(t_stack *stack);
void		arr_sort_checker(int *arr, int size);
void		arr_duplicates_checker(int *arr, int size);

void		handle_arg_error(int *stack_data, int size);

void		quick_sort_arr(int *arr, int L, int R);

void		hard_coding_three(t_stack *stack);

void		sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data);

void		first_sort_stack_b(t_stack *stack_a, t_stack *stack_b, int *sorted_data);

void		r_a(t_stack *stack_a, int *best_ra_c);
void		r_b(t_stack *stack_b, int *best_rb_c);

int			count_ra(t_stack *stack_a, int b_content);


void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

#endif
