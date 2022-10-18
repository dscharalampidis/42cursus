/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/18 18:51:22 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *
	ps_conv_argvtoarr(char **argv, char *delim)
{
	int		i;
	char	*tmp;
	char	*arr;

	i = 1;
	arr = ft_strdup(argv[i]);
	while (argv[++i])
	{
		tmp = arr;
		arr = ft_strjoin(arr, delim);
		free(tmp);
		tmp = arr;
		arr = ft_strjoin(arr, argv[i]);
		free(tmp);
	}
	return (arr);
}

int
	main(int argc, char **argv)
{
	char	*arr;

	arr = NULL;
	if (argc > 1)
		arr = ps_conv_argvtoarr(argv, "-");
	ft_printf("%s\n", arr);
	free(arr);
	return (0);
}
