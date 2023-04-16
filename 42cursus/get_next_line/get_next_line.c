/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:54 by haekang           #+#    #+#             */
/*   Updated: 2023/04/13 20:09:03 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*arr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (arr == NULL)
		return (NULL);
	arr[i + j] = '\0';
	while (--j >= 0)
		arr[i + j] = s2[j];
	while (--i >= 0)
		arr[i] = s1[i];
	return (arr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}


// test
char *get_next_line(int fd)
{
    char *buffer;
    ssize_t read_len;
    static char *save;
    char *i;
    int idx;
    char *result;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0) // read할 때마다 파일 포인터가 이동해서 다음 호출에서는 파일내의 다음 데이터를 읽게됨 
    {
        buffer[read_len] = '\0';
        if (save == NULL) // 처음 함수가 호출 되어 save 변수를 접근 했을 때
            save = strdup(buffer); // 버퍼를 담아줌
        else // 이전에 버퍼를 save에 담은적이 있으면
            save = ft_strjoin(save, buffer); // save와 버퍼를 합쳐줌
        if (ft_strchr(save, '\n')) // save에서 \n을 찾았을 때
            break; // 반복 종료
    } // 버퍼에 담아서 save에 넣어주는 반복문
    free(buffer); // 개행문자 찾았으니 버퍼 할당해제, save에는 개행문자가 담겨있음
    if (read_len == -1)
    {
        free(save);
        return (NULL);
    }
    if (read_len == 0 && save == NULL)
        return (NULL);
    i = ft_strchr(save, '\n');
    if (i != NULL)
    {
        idx = (i - save);
        save[idx] = '\0';
        result = ft_strdup(save);
        free(save);
        save = ft_strdup(i + 1);
    }
    else
    {
        result = ft_strdup(save);
        free(save);
        save = NULL;
    }
    return (result);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    
    fd = open("./test.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    
    close(fd);
    return (0);
}