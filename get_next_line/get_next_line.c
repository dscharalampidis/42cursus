/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:53:06 by dcharala          #+#    #+#             */
/*   Updated: 2022/08/29 06:10:55 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Find a character in a string. This function is used to find a newline
 * character in the buffer. */
char
	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/* Append each `buf` from `read()` to `joinedbuf` until there's at least one
 * newline character in it, or the file ends. */
char
	*append_buf(int fd, char *buf, char *joinedbuf)
{
	char	*tmp;
	int		bufsiz;

	bufsiz = 1;
	while (bufsiz)
	{
		bufsiz = read(fd, buf, BUFFER_SIZE);
		if (bufsiz == -1)
			return (NULL);
		else if (bufsiz == 0)
			break ;
		buf[bufsiz] = '\0';
		if (!joinedbuf)
			joinedbuf = ft_strdup("");
		tmp = joinedbuf;
		joinedbuf = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (joinedbuf);
}

/* Separate the `line` to be printed from the `joinedbuf` by adding a
 * terminating null after the newline character. Then return the rest of the
 * `joinedbuf`. */
char
	*separate_line_from_joinedbuf(char *line)
{
	size_t	i;
	char	*joinedbuf;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (NULL);
	joinedbuf = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*joinedbuf)
	{
		free(joinedbuf);
		joinedbuf = NULL;
	}
	line[i + 1] = '\0';
	return (joinedbuf);
}

/* Get and print a line from the `joinedbuf` until there's nothing left in it.
 * */
char
	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*joinedbuf;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = append_buf(fd, buf, joinedbuf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	joinedbuf = separate_line_from_joinedbuf(line);
	return (line);
}
