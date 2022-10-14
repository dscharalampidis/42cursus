/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 03:57:48 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 20:10:55 by dcharala         ###   ########.fr       */
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

/* Copy a character from one place in memory to another. This is a helper
 * function used by many other functions. */
void
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

/* Merge two strings into a new one. This function is used to append each `buf`
 * from `read()` to the previous one. */
char
	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, str1, len1);
	ft_memcpy(joined + len1, str2, len2);
	joined[len1 + len2] = '\0';
	return (joined);
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
