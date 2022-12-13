/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 03:14:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/12/13 19:25:09 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <string.h>
# include <errno.h>
# include <sys/wait.h> // Linux

/* errors.c */
void	error_file(char *file);
void	error_process_retry(void);
void	error_process(void);
void	error_cmd(char *cmd);
void	chk_args(int argc);

/* processes.c */
void	child1_process(int *p_fd, char **argv, char **envp, int fd);
void	child2_process(int *p_fd, char **argv, char **envp, int fd);
void	pipex(char **argv, char **envp);

/* utilities.c */
void	chk_fd(int *fd, char **argv);
char	**get_path(char **envp);
char	*get_line(char *cmd, char **arr);

#endif
