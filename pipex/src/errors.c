/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:33:02 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 19:27:48 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	error_file(char *file)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void
	error_process_retry(void)
{
	ft_putstr_fd("pipex: fork: retry: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void
	error_process(void)
{
	ft_putstr_fd("pipex: fork: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void
	error_cmd(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (EXIT_FAILURE);
}

void
	chk_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("pipex: syntax error\n", 2);
		exit (EXIT_SUCCESS);
	}
}
