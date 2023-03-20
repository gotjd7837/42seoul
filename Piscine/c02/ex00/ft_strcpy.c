/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:13:21 by haekang           #+#    #+#             */
/*   Updated: 2023/02/20 00:23:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
 * src가 널값이 나올 때 까지 반복해서 dest에 복사
 * 증가하고 나오므로 dest에 널값 넣어준다
 * dest 리턴
*/
/*
int	main(void)
{
	char	dest[7] = {'a','b','c','d','e','f'};
	char	src[4] = {'s','c','v'};

	printf("%s\n",dest);
	printf("%s\n",src);

	ft_strcpy(dest, src);

	printf("%s\n",dest);
	printf("%s\n",src);

}*/
