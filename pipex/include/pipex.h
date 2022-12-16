/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:14:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/16 20:49:36 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# ifdef __linux__
#  include <string.h>
#  include <errno.h>
#  include <sys/wait.h>
# elif __APPLE__
#  include <string.h>
#  include <errno.h>
# endif

/* errors.c */
void	error_file(char *prog_name, char *file);
void	error_process_retry(char *prog_name);
void	error_process(char *prog_name);
void	error_cmd(char *prog_name, char *cmd);
void	chk_args(char *prog_name, int argc);

/* processes.c */
void	child_p1(int *p_fd, char **argv, char **envp, int fd);
void	child_p2(int *p_fd, char **argv, char **envp, int fd);
void	pipex(char **argv, char **envp);

/* utilities.c */
void	chk_fd(int *fd, char **argv);
char	**get_path(char *prog_name, char **envp);
char	*get_line(char *prog_name, char *cmd, char **arr);

#endif
