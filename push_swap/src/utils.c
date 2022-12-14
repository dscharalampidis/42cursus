/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:37:56 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/21 23:55:59 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (error == 'Y')
		ps_error();
}

void
	ps_free_list(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->nxt;
		free(tmp);
	}
}
