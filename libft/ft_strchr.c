/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:27:41 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 05:32:54 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strchr(const char *ptr, int chr)
{
	char	*str;

	str = (char *)ptr;
	while (*str != (unsigned char)chr)
	{
		if (*str == 0)
			return (NULL);
		str++;
	}
	return (str);
}
