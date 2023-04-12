/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:54 by haekang           #+#    #+#             */
/*   Updated: 2023/04/12 20:41:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int gnl_strchr(const char *s, int c)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    if (c == '\0')
        return (0);
    return (0);
}

char	*ft_str_cpy(const char *s1, const char *s2, char *arr)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (arr == NULL)
		return (NULL);
	ft_str_cpy(s1, s2, arr);
	return (arr);
}

char *get_next_line(int fd)
{
    char *buffer;
    ssize_t read_len;
    static char *save = NULL;
    int i;
    char *result = NULL;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0) // read할 때마다 파일 포인터가 이동해서 다음 호출에서는 파일내의 다음 데이터를 읽게됨 
    {
        buffer[read_len] = '\0';
        if (save == NULL)
            save = strdup(buffer);
        else
            save = ft_strjoin(save, buffer);
        if (gnl_strchr(save, '\n'))
            break;
    }
    free(buffer);
    buffer = NULL;
    i = gnl_strchr(save, '\n');
    if (gnl_strchr(save, '\n'))
    {
        *(save + i) = '\0';
        result = save;
        save = save + i + 1;
    }
    else if (save != NULL)
    {
        result = save;
        save = NULL;
    }
    return (result);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
//     int fd;
    
//     fd = open("./test.txt", O_RDONLY);
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
    
//     close(fd);
//     return (0);
// }