/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:59:36 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 23:02:36 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	child_p1(int *p_fd, char **argv, char **envp, int fd)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(fd, 0);
	dup2(p_fd[1], 1);
	cmd = ft_split(argv[2], ' ');
	path = get_path(argv[0], envp);
	line = get_line(argv[0], cmd[0], path);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	execve(line, cmd, envp);
}

void
	child_p2(int *p_fd, char **argv, char **envp, int fd)
{
	char	**cmd;
	char	**path;
	char	*line;

	dup2(p_fd[0], 0);
	dup2(fd, 1);
	cmd = ft_split(argv[3], ' ');
	path = get_path(argv[0], envp);
	line = get_line(argv[0], cmd[0], path);
	close(fd);
	close(p_fd[1]);
	close(p_fd[0]);
	execve(line, cmd, envp);
}

pid_t
	fork_retry(pid_t pid, char *prog_name)
{
	int	i;

	i = 0;
	while (i < 4 && pid == -1)
	{
		pid = fork();
		if (pid == -1)
			error_process_retry(prog_name);
		i++;
		sleep(i);
	}
	return (pid);
}

void
	pipex(char **argv, char **envp)
{
	int		fd[2];
	int		p_fd[2];
	pid_t	pid;

	chk_fd(fd, argv);
	if (pipe(p_fd) == -1)
		error_process(argv[0]);
	pid = fork_retry(-1, argv[0]);
	if (pid == -1)
		error_process(argv[0]);
	if (pid == 0)
		child_p1(p_fd, argv, envp, fd[0]);
	pid = fork_retry(-1, argv[0]);
	if (pid == -1)
		error_process(argv[0]);
	if (pid == 0)
		child_p2(p_fd, argv, envp, fd[1]);
	close(fd[0]);
	close(fd[1]);
	close(p_fd[0]);
	close(p_fd[1]);
	wait(0);
	wait(0);
}
