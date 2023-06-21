/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:11 by haekang           #+#    #+#             */
/*   Updated: 2023/06/21 16:09:25 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	push_swap_atoi(const char *str)
{
	int			flag;
	long long	result;

	flag = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
			print_error();
	}
	return (result * flag);
}

void	av_to_stack(t_stack *stack, char **split)
{
	t_node		*node;
	long long	arg;
	int			i;

	i = 0;
	while (split[i] != NULL)
	{
		arg = push_swap_atoi(split[i]);
		if (arg > 2147483647 || arg < -2147483648)
			print_error();
		node = new_node(arg);
		push_top_stack(stack, node);
		i++;
	}
}

void	*arg_parsing(t_stack *stack, int ac, char *av[])
{
	int		i;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		av_to_stack(stack, split);
		i++;
	}
}

// 1. 정수가 아닌 값이 들어왔을 때 'Error' 출력

// 2. 정수가 중복해서 들어왔을 때 'Error' 출력

// 3. MAXINT 보다 큰 값 혹은 MININT보다 작은 값이 들어왔을때 'Error' 출력

// 4. 인자 없이, 혹은 인자가 하나밖에 없거나 이미 정렬된 채로 실행되면 아무것도 출력하지 않고 종료

// ㅈㅜㅇ보ㄱ이랑 정렬된채로 들들어어왔왔을을때 처처리만 남음