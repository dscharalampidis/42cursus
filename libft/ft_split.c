/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:59:20 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/14 02:26:25 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	cnt_words(char *str, char delim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if ((str[i] != delim && str[i + 1] == delim)
			|| (str[i] != delim && str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static int
	find_word_len(char *word, char delim)
{
	int	i;

	i = 0;
	while (word[i] != delim && word[i] != 0)
		i++;
	return (i);
}

static void
	*free_buf(char *buf[])
{
	int	i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
	return (NULL);
}

static char
	**split_words(const char *s, char c, char **buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			k = find_word_len((char *)(s + i), c);
			buf[j] = ft_substr(&s[i], 0, k);
			if (!buf[j])
				return (free_buf(buf));
			i += (k -1);
			j++;
		}
		i++;
	}
	buf[j] = NULL;
	return (buf);
}

char
	**ft_split(const char *s, char c)
{
	char	**buf;

	if (!s)
		return (NULL);
	buf = (char **)malloc(sizeof(char *) * (cnt_words((char *)s, c) + 1));
	if (!buf)
		return (NULL);
	return (split_words(s, c, buf));
}
