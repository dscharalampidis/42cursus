/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:33:02 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 23:28:03 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	error_file(char *prog_name, char *file)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_SUCCESS);
}

void
	error_process_retry(char *prog_name)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("fork: retry: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void
	error_process(char *prog_name)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("fork: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void
	error_cmd(char *prog_name, char *cmd)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (EXIT_FAILURE);
}

void
	chk_args(char *prog_name, int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd(prog_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("syntax error\n", 2);
		exit (EXIT_FAILURE);
	}
}
