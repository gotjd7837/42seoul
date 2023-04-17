/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:54 by haekang           #+#    #+#             */
/*   Updated: 2023/04/17 22:04:23 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_update(char *save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(save, buf);
	free(save);
	return (tmp);
}

static char	*get_next_save(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	i += 1;
	j = 0;
	while (save[i])
		line[j++] = save[i++];
	line[j] = '\0';
	free(save);
	return (line);
}


static char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\0')
		line[i] = '\0';
	else if (save[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	return (line);
}

static char	*get_save(int fd, char *save)
{
	char	*buf;
	int		byte_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		if (!save)
			save = ft_strdup("");
		save = save_update(save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = get_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = get_next_save(save);
	return (line);
}
