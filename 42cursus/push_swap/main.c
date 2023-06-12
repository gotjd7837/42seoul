/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:46:24 by haekang           #+#    #+#             */
/*   Updated: 2023/06/12 17:42:39 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

t_node	*new_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = content;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);

	stack->top = new_node(0);
	stack->bottom = new_node(0);

	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;

	stack->size = 0;
	return (stack);
}

int	main(int ac, char *av[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*arg_arr;//인자들을 int형 배열로 변환해서 넣을거임

	if (ac < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	arg_arr = av_to_arr(ac, av);//인자들을 받아서 int형 배열로 만듬과 동시에 에러처리까지
	//int형 배열을 stack_a에 넣어줄거임
	//그다음 stack_a를 정렬함
}

// 1. 정수가 아닌 값이 들어왔을 때 'Error' 출력

// 2. 정수가 중복해서 들어왔을 때 'Error' 출력

// 3. MAXINT 보다 큰 값 혹은 MININT보다 작은 값이 들어왔을때 'Error' 출력

// 4. 인자 없이, 혹은 인자가 하나밖에 없거나 이미 정렬된 채로 실행되면 아무것도 출력하지 않고 종료