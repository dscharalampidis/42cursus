/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:31:30 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 04:14:16 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int
	main(int argc, char **argv, char **envp)
{
	chk_args(argc);
	pipex(argv, envp);
	return (0);
}
