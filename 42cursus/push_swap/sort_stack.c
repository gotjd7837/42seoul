/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:55:40 by haekang           #+#    #+#             */
/*   Updated: 2023/06/28 21:25:05 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_instr_cnt(int *best_ra_c, int *best_rb_c, int ra_c, int rb_c)
{
	int	sum_current;
	int	sum_c;
	int	current_rb;
	int	current_ra;

	if (*best_ra_c < 0)
		current_ra = *best_ra_c * -1;
	else
		current_ra = *best_ra_c;
	if (*best_rb_c < 0)
		current_rb = *best_rb_c * -1;
	else
		current_rb = *best_rb_c;
	if (ra_c < 0)
		ra_c = ra_c * -1;
	if (rb_c < 0)
		rb_c = rb_c * -1;
	sum_current = current_ra + current_rb;
	sum_c = ra_c + rb_c;
	if (sum_c < sum_current)
		return (1);
	else
		return (0);
}

static void	best_instr_cnt(t_stack *a, t_stack *b, int *best_ra_c, int *best_rb_c)
{
	int		i;
	int		ra_c;
	int		rb_c;
	t_node	*node;

	i = 0;
	node = b->top->next;
	while (i < b->size)
	{
		ra_c = count_ra(a, node->content);//이부분이 문젠가 ?
		if (i > (b->size / 2))
			rb_c = (b->size - i) * -1;
		else
			rb_c = i;
		if (i == 0 || compare_instr_cnt(best_ra_c, best_rb_c, ra_c, rb_c) == 1)
		{
			*best_ra_c = ra_c;
			*best_rb_c = rb_c;

			printf("-------------베스트 로테이션 값-------------\n\n");
			printf("베스트 ra : %d\n", best_ra_c);
			printf("베스트 rb : %d\n", best_rb_c);
			printf("-------------베스트 로테이션 값-------------\n\n");
		}
		node = node->next;
		i++;
	}
}

static void	second_sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	best_ra_c;
	int	best_rb_c;

	best_ra_c = 0;
	best_rb_c = 0;
	while (stack_b->size != 0)
	{
		best_instr_cnt(stack_a, stack_b, &best_ra_c, &best_rb_c);//이 부분에서 문제 생기는거 같은데 rr변수를 하나 만들어서 따로 ra rb계산해서 반환하는 함수 만들어도 좋을듯

		r_a(stack_a, &best_ra_c);
		r_b(stack_b, &best_rb_c);
		pa(stack_a, stack_b);
		printf("a 스택 탑값 : %d\n", stack_a->top->next->content);
	}
	// rr_a_b(stack_a, stack_b, &best_ra_c, &best_rb_c);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int *sorted_data)
{
	printf("-------------첫 번째 정렬 부분 -------------\n");
	first_sort_stack_b(stack_a, stack_b, sorted_data);
	printf("-------------첫 번째 정렬 부분 -------------\n\n\n");


	printf("-------------하드 코딩 부분-------------\n");
	hard_coding_three(stack_a);
	printf("-------------하드 코딩 부분-------------\n");
	printf("%d\n", stack_a->top->next->content);
	printf("%d\n", stack_a->top->next->next->content);
	printf("%d\n", stack_a->top->next->next->next->content);
	printf("-------------하드 코딩 부분-------------\n\n\n");

	printf("-------------두 번째 정렬 부분 -------------\n\n\n");
	second_sort_stack_a(stack_a, stack_b);
	printf("-------------두 번째 정렬 부분 -------------\n\n");
}
