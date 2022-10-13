/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:19:48 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 03:40:19 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *buf, int chr, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)buf;
	while (i < len)
		str[i++] = chr;
	return (str);
}
