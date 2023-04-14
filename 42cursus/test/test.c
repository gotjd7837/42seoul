/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:25:21 by haekang           #+#    #+#             */
/*   Updated: 2023/04/15 07:21:42 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define BUFFER_SIZE 10

static char *get_line(char **save)
{
	// 조건문으로 chr \n이 검출 됐을 때 res 검출 안됐을 때 (마지막줄) 나눠서 ㄱㄱ
	// chr로 개행의 주솟값 받아옴
	// 주솟값의 문자를 널문자로 변환

	char *res;
	char *tmp;
	int len;

	if (ft_strchr(*save, '\n'))
	{
		len = (ft_strchr(*save, '\n') - *save);
		res = ft_substr(*save, 0, len);
		tmp = *save;
		*save = ft_strdup(tmp + len + 1);
		free(tmp);
		return (res);
	}
	else // 개행이 없다는 것이므로 마지막줄이라는 것
	{
		res = ft_strdup(*save);
		free(*save);
		return (res);
	}

}

static void	get_save(int fd, char **save, char **buf)
{
	ssize_t	read_len;
	char	*tmp;

	if (ft_strchr(*save, '\n'))
	{
		free(buf);
		return ;
	}
	while ((read_len = read(fd, *buf, BUFFER_SIZE)) > 0)
	{
		(*buf)[read_len] = '\0';
		if (*save == NULL)
			*save = ft_strdup(*buf);
		else
		{
			tmp = *save;
			*save = ft_strjoin(tmp, *buf);
			free(tmp);
		}
		if (ft_strchr(*save, '\n'))
			break;
	}
	free(buf);
}

char	*get_next_line(int fd) // 호출 시 파일의 개행 전까지 출력
{
    static char	*save;
	char	*buf;
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	get_save(fd, &save, &buf); // save에 개행이 없으면, read를 해서 버퍼랑 조인해줌
	res = get_line(&save); // save에서 개행을 기준으로 앞을 반환, 뒤를 save로 치환한다
	return (res);
}