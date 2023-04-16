/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:25:21 by haekang           #+#    #+#             */
/*   Updated: 2023/04/16 16:15:02 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char *get_next_save(char *save)
{
	char *new_save;
	int len;

	if (ft_strchr(save, '\n'))
	{
		len = (ft_strchr(save, '\n') - save);
		new_save = ft_strdup(save + (len + 1));
		free(save);
	}
	else
	{
		free(save);
		new_save = NULL;
	}
	return (new_save);
}

static char *get_line(char *save)
{
	// char *line;
	// int	i;

	// i = 0;
	// if (!save[i])
	// 	return (NULL);
	// while (save[i] && save[i] != '\n')
	// 	i++;
	// line = (char *)malloc(sizeof(char) * (i + 2));
	if (ft_strchr(save, '\n'))
	{
		len = (ft_strchr(save, '\n') - save);
		line = ft_substr(save, 0, (len + 1));
	}
	else
		line = ft_strdup(save);
	return (line);
}

static char	*get_save(int fd, char *save)
{
	char	*buf;
	char	*tmp;
	int		read_len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // 널가드 어째하지 ?
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		if (!save)
			save = ft_strdup("");
		else
		{
			tmp = save;
			save = ft_strjoin(tmp, buf);
			free(tmp);
		}
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
    return(line);
}