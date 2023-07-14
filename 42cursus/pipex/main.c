/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:37:31 by haekang           #+#    #+#             */
/*   Updated: 2023/07/15 04:21:26 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*slash_cmd;
	char	*path_cmd;

	// if (access(cmd, X_OK) == 0)
	// 	return (cmd);
	// else
		
	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	if (slash_cmd == NULL)
		return (NULL);
	while (path[i] != NULL)
	{
		path_cmd = ft_strjoin(path[i], slash_cmd);
		if (access(path_cmd, X_OK) == 0)
		{
			free(slash_cmd);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	return (NULL);
}

static void	first_child(t_pipex *info, char **envp)
{
	char	*cmd1_path;

	cmd1_path = find_cmd_path(info->path, info->cmd1_av[0]);
	if (cmd1_path == NULL)
		write_error_and_exit("error cmd1: command not found\n");
	close(info->pipefd[0]);
	dup2(info->infile, STDIN_FILENO);
	dup2(info->pipefd[1], STDOUT_FILENO);
	close(info->infile);
	close(info->pipefd[1]);
	close(info->outfile);
	execve(cmd1_path, info->cmd1_av, envp);
}

static void	second_child(t_pipex *info, char **envp)
{
	char	*cmd2_path;

	cmd2_path = find_cmd_path(info->path, info->cmd2_av[0]);
	if (cmd2_path == NULL)
		write_error_and_exit("error cmd2: command not found\n");
	dup2(info->pipefd[0], STDIN_FILENO);
	dup2(info->outfile, STDOUT_FILENO);
	close(info->pipefd[0]);
	close(info->outfile);
	close(info->infile);
	execve(cmd2_path, info->cmd2_av, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*info;
	int		pid1;
	int		pid2;

	if (ac != 5)
		write_error_and_exit("wrong number of arguments\n");
	info = set_info(av, envp);
	pid1 = fork();
	if (pid1 < 0)
		perror_and_exit("fork failed");
	if (pid1 == 0)
		first_child(info, envp);
	close(info->pipefd[1]);

	//자식 프로세스를 두개 만들 필요가 있나 음
	//원본 파이프 에서는 마지막 프로세스가 에러나야 exit(1)인데 ㅋㅋ 즉 원본은 첫번째 프로세스는 자식 프로세스인거고 마지막이 부모 프로세스인거임
	
	pid2 = fork();
	if (pid2 < 0)
		perror_and_exit("fork failed");
	if (pid2 == 0)
		second_child(info, envp);
	close(info->pipefd[0]);
	while (wait(NULL) != -1)
		;
	exit(0);
}
//절대경로로 들어올 때 처리해줘
//명령어가 ""와 같이 들어올 때 처리해줘야해
//잘못된 cmd같은게 들어왔을 때 에러 출력해줘야한다. perror는 시스템콜 함수가 에러가 떳을 때 에러문을 저장하고 그걸 출력하지만 cmd를 못찾는 그런건 시스템 콜 함수를 사용하지 않기 때문에 내가 따로 에러문을 처리해야한다.