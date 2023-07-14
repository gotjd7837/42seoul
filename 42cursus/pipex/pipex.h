/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:36:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/14 19:19:29 by haekang          ###   ########.fr       */
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
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*path_cmd1;
	char	*path_cmd2;
}			t_pipex;

void	print_error(char *str);

t_pipex	*set_info(char **av, char **envp);

#endif