/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_passing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:50:11 by haekang           #+#    #+#             */
/*   Updated: 2023/06/12 18:52:37 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int get_arr_size(int ac, char *av[])
{

}

int *av_to_arr(int ac, char *av[])
{
    int *result;
    int arr_size;

    arr_size = get_arr_size(ac, av);//모든 숫자의 size
    result = (int *)malloc(arr_size * sizeof(int));
    if (result == NULL)
        return (0);//에러 출력
    

    return (result);

//받아온 인자를 스플릿으로 전부 하나의 숫자형 문자를 담는
//문자열로 만든 뒤 문자열의 전체 갯수 size를 구해서
//size만큼 동적 할당해서 int형 배열을 만든다
}