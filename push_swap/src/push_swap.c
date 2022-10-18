/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/18 19:56:16 by dcharala         ###   ########.fr       */
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

int
	main(int argc, char **argv)
{
	char	**arrv;
	int		i;

	arrv = NULL;
	if (argc > 1)
		arrv = ps_conv_argvtoarrv(argv);
	i = -1;
	while (arrv[++i])
	{
		ft_printf("%s\n", arrv[i]);
		free(arrv[i]);
	}
	free(arrv);
	return (0);
}
