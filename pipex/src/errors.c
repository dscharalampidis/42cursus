/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:33:02 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 04:13:44 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	chk_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("pipex: syntax error\n", 2);
		exit (EXIT_SUCCESS);
	}
}
