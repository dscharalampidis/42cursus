/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:31:30 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 22:58:13 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int
	main(int argc, char **argv, char **envp)
{
	chk_args(argv[0], argc);
	pipex(argv, envp);
	return (0);
}
