/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:34:09 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 05:38:49 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *ptr, int chr)
{
	char	*p;

	p = (char *)ptr + ft_strlen((char *)ptr);
	while (*p != (unsigned char)chr)
	{
		if (p == (char *)ptr)
			return (NULL);
		p--;
	}
	return (p);
}
