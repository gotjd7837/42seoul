/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_passing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:11 by haekang           #+#    #+#             */
/*   Updated: 2023/06/20 19:44:54 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_arr_size(int ac, char *av[])
{

}

void *av_to_stack(t_stack *stack, int ac, char *av[])
{
    int i;

    i = 1;
    while (i < ac)
    {
        
    }
    
//받아온 인자를 스플릿으로 전부 하나의 숫자형 문자를 담는
//문자열로 만든 뒤 문자열의 전체 갯수 size를 구해서
//size만큼 동적 할당해서 int형 배열을 만든다
}

// 1. 정수가 아닌 값이 들어왔을 때 'Error' 출력

// 2. 정수가 중복해서 들어왔을 때 'Error' 출력

// 3. MAXINT 보다 큰 값 혹은 MININT보다 작은 값이 들어왔을때 'Error' 출력

// 4. 인자 없이, 혹은 인자가 하나밖에 없거나 이미 정렬된 채로 실행되면 아무것도 출력하지 않고 종료