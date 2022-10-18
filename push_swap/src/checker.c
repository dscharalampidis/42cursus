/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:42:32 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/18 21:43:09 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_chk_invalid_arg(char **arrv)
{
	int			i;
	int			j;
	long long	nbr;

	i = -1;
	while (arrv[++i])
	{
		j = -1;
		while (arrv[i][++j])
		{
			if (arrv[i][j] == 43 || arrv[i][j] == 45)
				j++;
			if (!(ft_isdigit(arrv[i][j])))
				ps_free(arrv, 'E');
			j++;
		}
		nbr = ft_atoi(arrv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ps_free(arrv, 1);
	}
}

void
	ps_chk_duplicate_arg(char **arrv)
{
	int	i;
	int	j;

	i = -1;
	while (arrv[++i])
	{
		j = i;
		while (arrv[++j])
		{
			if (ft_atoi(arrv[i]) == ft_atoi(arrv[j]))
					ps_free(arrv, 'E');
		}
	}
}
