/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:57:48 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 20:34:14 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t
	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char
	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (++i < len)
		buf[i] = s[i];
	buf[i] = 0;
	return (buf);
}

void
	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}

char
	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*buf;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buf)
		return (NULL);
	ft_memcpy(buf, s1, len1);
	ft_memcpy(buf + len1, s2, len2);
	buf[len1 + len2] = 0;
	return (buf);
}

/* Extract a substring from a string. This function is used to get the remainder
 * of `joinedbuf` after removing a line from it. */
char
	*ft_substr(char const *str, unsigned int start, size_t n)
{
	size_t		len;
	char		*sub;
	const char	*ptr;

	len = ft_strlen(str);
	if (len < start)
		start = len;
	str += start;
	ptr = str;
	while (*ptr && n)
	{
		ptr++;
		n--;
	}
	n = ptr - str;
	sub = (char *)malloc(sizeof(char) * (n + 1));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, str, n);
	sub[n] = '\0';
	return (sub);
}
