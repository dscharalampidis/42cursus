/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:18:34 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 23:24:17 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*buf;
	char	*str;

	str = (char *)s;
	len = ft_strlen((char *)s);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (++i < len)
		buf[i] = str[i];
	buf[i] = 0;
	return (buf);
}
