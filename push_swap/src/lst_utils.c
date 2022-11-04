/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:57:51 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/04 17:30:30 by dcharala         ###   ########.fr       */
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

int
	ps_find_min_i(t_node *head)
{
	int		i;
	int		min;
	int		min_i;
	t_node	*curr;

	i = 0;
	min = INT_MAX;
	min_i = 1;
	curr = head;
	while (curr)
	{
		++i;
		if (curr->nbr < min)
		{
			min = curr->nbr;
			min_i = i;
		}
		curr = curr->nxt;
	}
	return (min_i);
}

t_node*
	ps_dup_lst(t_node *head)
{
	t_node	*copy;

	if (!head)
		return (NULL);
	copy = (t_node *)malloc(sizeof(t_node));
	if (!copy)
		exit (EXIT_FAILURE);
	copy->nbr = head->nbr;
	copy->nxt = ps_dup_lst(head->nxt);
	return (copy);
}
