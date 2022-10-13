/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:15:22 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 06:27:40 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = -1;
	while (++i < len && haystack[i])
	{
		j = -1;
		while (i + ++j < len && needle[j] && haystack[i + j] == needle[j])
			if (needle[j + 1] == 0)
				return ((char *)&haystack[i]);
	}
	return (NULL);
}

