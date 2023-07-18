/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:36:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/19 06:56:33 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**cmd1_av;
	char	**cmd2_av;
	char	**path;
}			t_pipex;

void	perror_and_exit(char *str);
void	write_error_and_exit(char *str);

t_pipex	*set_info(char **av, char **envp);

void	info_free(t_pipex *info);

char	*find_cmd_abspath(char **path, char *cmd);

#endif