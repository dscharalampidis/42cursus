/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 05:40:46 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 05:49:12 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = -1;
	while (++i < n - 1 && str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i]);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
