/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:57:51 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 12:33:46 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_free_lst(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	while (curr)
	{
		tmp = curr;
		curr = curr->nxt;
		free(tmp);
	}
	*head = NULL;
}

int
	ps_find_lst_len(t_node *head)
{
	if (!head)
		return (0);
	return (1 + ps_find_lst_len(head->nxt));
}

int
	ps_chk_lst_sorted(t_node *head)
{
	if (head == NULL)
		return (1);
	while (head->nxt)
	{
		if (head->nbr > head->nxt->nbr)
			return (0);
		head = head->nxt;
	}
	return (1);
}
