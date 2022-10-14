/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:32:35 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 21:53:58 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef __linux__
#  include <sys/stat.h>
#  include <fcntl.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <limits.h>
#  include <stddef.h>
# elif __APPLE__
#  include <fcntl.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <sys/types.h>
#  include <sys/uio.h>
#  include <unistd.h>
#  include <limits.h>
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > INT_MAX - 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/* get_next_line.c */
char	*ft_strchr(const char *s, int c);
char	*append_buf(int fd, char *buf, char *joinedbuf);
char	*separate_line_from_joinedbuf(char *line);
char	*get_next_line(int fd);

/* get_next_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
