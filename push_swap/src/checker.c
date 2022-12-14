/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:42:32 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/22 02:23:49 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ps_chk_nil(char *arr)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(arr))
	{
		if (arr[i] == 43 || arr[i] == 45)
			i++;
		if (arr[i] != 48)
			return (1);
	}
	return (0);
}

void
	ps_chk_invalid_arg(char **arrv)
{
	int			i;
	int			j;
	long long	nbr;

	i = -1;
	while (arrv[++i])
	{
		j = 0;
		while (arrv[i][j])
		{
			if (arrv[i][j] == 43 || arrv[i][j] == 45)
				j++;
			if (!(ft_isdigit(arrv[i][j++])))
				ps_free(arrv, 'Y');
		}
		nbr = ft_atoi(arrv[i]);
		if ((ft_strlen(arrv[i]) > 9 && nbr == 0)
			|| (ft_strlen(arrv[i]) > 9 && nbr == -1))
		{
			if (!ps_chk_nil(arrv[i]))
				;
			else
				ps_free(arrv, 'Y');
		}
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
				ps_free(arrv, 'Y');
		}
	}
}

char
	ps_chk_sorted(int *arr, size_t arrlen)
{
	size_t	i;

	i = -1;
	while (++i < arrlen - 1)
	{
		if (arr[i + 1] < arr[i])
			return ('N');
	}
	return ('Y');
}
