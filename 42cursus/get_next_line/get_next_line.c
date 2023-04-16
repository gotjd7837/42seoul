/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:54 by haekang           #+#    #+#             */
/*   Updated: 2023/04/16 16:15:00 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// static char	*ft_free(char *buffer, char *buf)
// {
// 	char	*temp;

// 	temp = ft_strjoin(buffer, buf);
// 	free(buffer);
// 	return (temp);
// }

// // delete line find
// static char	*ft_next(char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*line;

// 	i = 0;
// 	// find len of first line
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	// if eol == \0 return NULL
// 	if (!buffer[i])
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	// len of file - len of firstline + 1
// 	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
// 	i++;
// 	j = 0;
// 	// line == buffer
// 	while (buffer[i])
// 		line[j++] = buffer[i++];
// 	free(buffer);
// 	return (line);
// }

// // take line for return
// static char	*ft_line(char *buffer)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	// if no line return NULL
// 	if (!buffer[i])
// 		return (NULL);
// 	// go to the eol
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	// malloc to eol
// 	line = ft_calloc(i + 2, sizeof(char));
// 	i = 0;
// 	// line = buffer
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	// if eol is \0 or \n, replace eol by \n
// 	if (buffer[i] && buffer[i] == '\n')
// 		line[i++] = '\n';
// 	return (line);
// }

// static char	*read_file(int fd, char *res)
// {
// 	char	*buffer;
// 	int		byte_read;

// 	// malloc if res dont exist
// 	if (!res)
// 		res = ft_calloc(1, 1);
// 	// malloc buffer
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	byte_read = 1;
// 	while (byte_read > 0)
// 	{
// 		// while not eof read
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		// 0 to end for leak
// 		buffer[byte_read] = 0;
// 		// join and free
// 		res = ft_free(res, buffer);
// 		// quit if \n find
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	return (res);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	// error handling
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	buffer = read_file(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_line(buffer);
// 	buffer = ft_next(buffer);
// 	return (line);
// }





 ///////////////////////////////////////////////////////

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
		res = ft_substr(*save, 0, (len + 1));
		tmp = *save;
		*save = ft_strdup(tmp + (len + 1));
		free(tmp);
		return (res);
	}
	else // 개행이 없다는 것이므로 마지막줄이라는 것
	{
        res = ft_strdup(*save);
		free(*save);
        *save = NULL;
		return (res);
	}

}

static void	get_save(int fd, char **save)
{
	ssize_t	read_len;
	char	*tmp;
    char    *buf;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_len = 1;
	while (read_len > 0)
	{
        read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buf);
			return ;
		}
		buf[read_len] = '\0';
		if (*save == NULL)
			*save = ft_strdup(buf);
		else
		{
			tmp = *save;
			*save = ft_strjoin(tmp, buf);
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
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_save(fd, &save); // save에 개행이 없으면, read를 해서 버퍼랑 조인해줌
    if (!save)
        return (NULL);
	res = get_line(&save); // save에서 개행을 기준으로 앞을 반환, 뒤를 save로 치환한다
	return (res);
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
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
//     printf("%s\n", get_next_line(fd));
    
//     close(fd);
//     return (0);
// }