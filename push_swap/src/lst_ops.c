/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:31:15 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 01:32:55 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_insert_int_lst_head(t_node **head, int nbr, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->nbr = nbr;
	new_node->idx = idx;
	new_node->nxt = *head;
	*head = new_node;
}

void
	ps_insert_int_lst_tail(t_node **head, int nbr, int idx)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->nbr = nbr;
	new_node->idx = idx;
	new_node->nxt = NULL;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->nxt)
		curr = curr->nxt;
	curr->nxt = new_node;
}

void
	ps_remove_lst_head(t_node **head)
{
	t_node	*del_node;

	if (!head || !(*head))
		return ;
	del_node = *head;
	*head = (*head)->nxt;
	free(del_node);
}

void
	ps_remove_lst_tail(t_node **head)
{
	t_node	*curr;

	if (!(*head)->nxt)
		free(*head);
	curr = *head;
	while (curr->nxt->nxt)
		curr = curr->nxt;
	free(curr->nxt);
	curr->nxt = NULL;
}
