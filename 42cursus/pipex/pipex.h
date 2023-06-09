/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:36:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/09 21:40:24 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_pipex
{
    int infile;
    int outfile;
    int pipefd[2];
    char    **cmd1;
    char    **cmd2;
    char    **path;
    char    *path_cmd1;
    char    *path_cmd2;
    
}       t_pipex;

void	print_error(char *str);

#endif