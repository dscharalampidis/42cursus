/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:32:25 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 05:52:21 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)ptr;
	i = -1;
	while (++i < n)
		str[i] = 0;
}
