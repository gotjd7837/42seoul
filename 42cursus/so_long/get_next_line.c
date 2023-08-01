/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:38:54 by haekang           #+#    #+#             */
/*   Updated: 2023/08/01 19:06:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*save_update(char *save, char *buf)
{
	char	*tmp;

	tmp = save;
	save = ft_strjoin(save, buf);
	free(tmp);
	return (save);
}

static char	*get_next_save(char *save)
{
	char	*new_save;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = ft_substr(save, i + 1, (ft_strlen(save) - (i + 1)));
	free(save);
	return (new_save);
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
	if (!save[i])
		line = ft_strdup(save);
	else
		line = ft_substr(save, 0, (i + 1));
	return (line);
}

static char	*get_save(int fd, char *save)
{
	char	*buf;
	int		read_len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[read_len] = '\0';
		if (!save)
			save = ft_strdup("");
		save = save_update(save, buf);
		if (ft_strchr(save, '\n'))
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
