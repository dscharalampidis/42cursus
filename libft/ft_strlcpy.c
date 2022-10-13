/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:28:07 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 04:38:45 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	if (siz > 0)
	{
		i = -1;
		while (++i < (siz - 1) && src[i] != 0)
			dst[i] = src[i];
		dst[i] = 0;
	}
	return (ft_strlen((char *)src));
}
