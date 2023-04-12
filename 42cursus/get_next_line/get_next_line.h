/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:57:28 by haekang           #+#    #+#             */
/*   Updated: 2023/04/12 20:28:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int gnl_strchr(const char *s, int c);
char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str_cpy(const char *s1, const char *s2, char *arr);
size_t	ft_strlen(const char *str);


#endif