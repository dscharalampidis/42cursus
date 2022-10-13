/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:28:41 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 06:53:20 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long
	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					sgn;
	int					i;

	nbr = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 20)
		i++;
	if (str[i] == 45)
		sgn = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	if (sgn == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (sgn == -1 && nbr >= 9223372036854775808u)
		return (0);
	return (nbr * sgn);
}

