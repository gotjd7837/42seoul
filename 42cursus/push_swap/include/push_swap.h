/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:32 by haekang           #+#    #+#             */
/*   Updated: 2023/06/21 16:43:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

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

void		print_error(void);

void		*arg_parsing(t_stack *stack, int ac, char *av[]);
void		av_to_stack(t_stack *stack, char **split);
long long	push_swap_atoi(const char *str);

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
