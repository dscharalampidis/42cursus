/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:44:43 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 23:55:19 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*buf;
	char	*str;
	size_t	i;

	str = (char *)s;
	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (NULL);
	i = -1;
	while (++i < len && str[i + start] != 0)
		buf[i] = str[i + start];
	buf[i] = 0;
	return (buf);
}
