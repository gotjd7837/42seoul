/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:42:51 by haekang           #+#    #+#             */
/*   Updated: 2023/04/12 17:43:18 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gnl_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

char *get_next_line(int fd)
{
    char *buffer;
    static char *result;
    ssize_t read_len;
    char *tmp;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);

    while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[read_len] = '\0';
        if (result == NULL)
            result = strdup(buffer);
        else
        {
            tmp = strdup(result);
            free(result);
            result = (char *)malloc(sizeof(char) * (strlen(tmp) + read_len + 1));
            if (result == NULL)
                return (NULL);
            strcpy(result, tmp);
            strcat(result, buffer);
            free(tmp);
        }
        if (gnl_strchr(result, '\n'))
            break;
    }
    free(buffer);
    if (read_len < 0 || (read_len == 0 && result == NULL))
        return (NULL);

    tmp = strdup(result);
    free(result);
    result = (char *)malloc(sizeof(char) * (strlen(tmp) + 1));
    if (result == NULL)
        return (NULL);
    strcpy(result, tmp);
    free(tmp);
    return (result);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc == 2)
//     {
//         fd = open(argv[1], O_RDONLY);
//         while ((line = get_next_line(fd)))
//         {
//             printf("%s\n", line);
//             free(line);
//         }
//         close(fd);
//     }
//     return (0);
// }