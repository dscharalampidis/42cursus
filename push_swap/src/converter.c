/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:35:34 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/19 05:48:08 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char**
	ps_conv_argvtoarrv(char **argv)
{
	int		i;
	char	*tmp;
	char	*arr;
	char	**arrv;

	i = 1;
	arr = ft_strdup(argv[i]);
	while (argv[++i])
	{
		tmp = arr;
		arr = ft_strjoin(arr, " ");
		free(tmp);
		tmp = arr;
		arr = ft_strjoin(arr, argv[i]);
		free(tmp);
	}
	arrv = ft_split(arr, ' ');
	free(arr);
	return (arrv);
}

size_t
	ps_arrlen(char **arrv)
{
	size_t	i;

	i = -1;
	while (arrv[++i])
		;
	return (i);
}

int*
	ps_atoi_arr(char **arrv)
{
	int		*arr;
	size_t	i;
	size_t	j;

	i = ps_arrlen(arrv);
	arr = (int *)malloc(sizeof(arr[0]) * i);
	j = -1;
	while (++j < i)
		arr[j] = ft_atoi(arrv[j]);
	return (arr);
}
