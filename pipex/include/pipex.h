/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:14:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 04:09:39 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"

/* errors.c */
void	chk_args(int argc);

/* processes.c */
void	pipex(char **argv, char **envp);

/* utilities.c */

#endif

