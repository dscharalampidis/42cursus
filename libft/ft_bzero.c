/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:32:25 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 03:39:25 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
		str[i++] = 0;
}
