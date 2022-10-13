/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:28:41 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 08:21:26 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_atoi(const char *nptr)
{
	long int	nbr;
	int			sgn;

	nbr = 0;
	sgn = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 20)
		nptr++;
	if (*nptr == 45)
		sgn = -1;
	if (*nptr == 43 || *nptr == 45)
		nptr++;
	while (ft_isdigit(*nptr))
	{
		nbr = nbr * 10 + *nptr - 48;
		nptr++;
	}
	if (nbr * sgn > INT_MAX)
		return (-1);
	if (nbr * sgn < INT_MIN)
		return (0);
	return ((int)nbr * sgn);
}
