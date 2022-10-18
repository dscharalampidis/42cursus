/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/18 21:04:17 by dcharala         ###   ########.fr       */
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

void
	ps_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void
	ps_free(char **arrv, char error)
{
	int	i;

	i = -1;
	while (arrv[++i])
		free(arrv[i]);
	free(arrv);
	if (error == 'E')
		ps_error();
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

int
	main(int argc, char **argv)
{
	char	**arrv;
	int		i;

	arrv = NULL;
	if (argc > 1)
		arrv = ps_conv_argvtoarrv(argv);
	ps_chk_invalid_arg(arrv);
	i = -1;
	while (arrv[++i])
	{
		ft_printf("%s\n", arrv[i]);
		free(arrv[i]);
	}
	free(arrv);
	return (0);
}
