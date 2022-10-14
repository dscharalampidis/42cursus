/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:32:35 by dcharala          #+#    #+#             */
/*   Updated: 2022/09/06 05:33:08 by dcharala         ###   ########.fr       */
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

/* BUFSIZ is the default buffer size of the OS defined in the stdio.h */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

/* If BUFFER_SIZE is defined by the user to a value that results in exceeding
 * the maximum size of any variable in the program the compiler will complain
 * and set it to an unpredicable value. The below code set the buffer size to
 * zero when the user enters a number higher than the maximum integer to avoid
 * unexpected behaviour when malloc-ing a sizeof(char). The -1 makes sure no
 * overflow occurs when we add +1 for the terminating null. Check
 * get_next_line() for details.*/
# if BUFFER_SIZE > INT_MAX - 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_substr(char const *str, unsigned int start, size_t n);
char	*append_buf(int fd, char *buf, char *joinedbuf);
char	*separate_line_from_joinedbuf(char *line);
char	*get_next_line(int fd);

#endif
