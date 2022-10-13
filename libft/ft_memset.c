/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:19:48 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 04:17:35 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *ptr, int chr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
		str[i++] = chr;
	return (str);
}
