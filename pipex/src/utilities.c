/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:17:44 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 23:31:29 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	chk_fd(int *fd, char **argv)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		error_file(argv[0], argv[1]);
	fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		error_file(argv[0], argv[4]);
}

char
	**get_path(char *prog_name, char **envp)
{
	char	**arr;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			arr = ft_split(envp[i] + 5, ':');
			if (!arr)
				error_process(prog_name);
			return (arr);
		}
		i++;
	}
	return (NULL);
}

char
	*get_line(char *prog_name, char *cmd, char **arr)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(line, F_OK) == 0)
			return (line);
		else
			free(line);
		i++;
	}
	error_cmd(prog_name, cmd);
	return (NULL);
}
