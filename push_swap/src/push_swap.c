/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/19 05:17:11 by dcharala         ###   ########.fr       */
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

int*
	ps_atoi_arr(char **arrv)
{
	int		*arr;
	size_t	i;
	size_t	j;

	i = -1;
	while (arrv[++i])
		;
	arr = (int *)malloc(sizeof(i));
	j = -1;
	while (++j < i)
		arr[j] = ft_atoi(arrv[j]);
	return (arr);
}

int
	main(int argc, char **argv)
{
	char	**arrv;
	int		*arr;
	size_t	i;
	size_t	j;

	arrv = NULL;
	if (argc > 1)
		arrv = ps_conv_argvtoarrv(argv);
	ps_chk_invalid_arg(arrv);
	ps_chk_duplicate_arg(arrv);
	arr = ps_atoi_arr(arrv);
	i = -1;
	while (arrv[++i])
	{
		ft_printf("char: %s\n", arrv[i]);
		free(arrv[i]);
	}
	free(arrv);
	j = -1;
	while (++j < i)
		ft_printf("int: %d\n", arr[j]);
	free(arr);
	return (0);
}
