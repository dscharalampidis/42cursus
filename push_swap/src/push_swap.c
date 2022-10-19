/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/19 06:59:09 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ps_parse_arg(int argc, char **argv)
{
	char	**arrv;
	int		*arr;
	size_t	arrlen;
	char	sorted;
	size_t	i;
	size_t	j;

	arrv = NULL;
	if (argc > 1)
		arrv = ps_conv_argvtoarrv(argv);
	ps_chk_invalid_arg(arrv);
	ps_chk_duplicate_arg(arrv);
	arr = ps_atoi_arr(arrv);
	arrlen = ps_arrlen(arrv);
	sorted = ps_chk_sorted(arr, arrlen);
	if (sorted == 'Y')
	{
		ps_free(arrv, 'N');
		free(arr);
		return (0);
	}
	/* start the sorting algo */
	i = -1;
	while (arrv[++i])
		ft_printf("char: %s\n", arrv[i]);
	ps_free(arrv, 'N');
	j = -1;
	while (++j < i)
		ft_printf("int: %d\n", arr[j]);
	free(arr);
	return (0);
}

int
	main(int argc, char **argv)
{
	ps_parse_arg(argc, argv);
	return (0);
}
