/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:51:32 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 02:27:57 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_rotate_lst(t_node **head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *head;
	tmp = curr;
	while (curr->nxt)
		curr = curr->nxt;
	curr->nxt = *head;
	*head = tmp->nxt;
	tmp->nxt = NULL;
}

void
	ps_reverse_rotate_lst(t_node **head)
{
	t_node	*curr;

	curr = *head;
	while (curr->nxt)
		curr = curr->nxt;
	ps_insert_int_lst_head(head, curr->nbr, curr->idx);
	ps_remove_lst_tail(head);
}

void
	ps_ra(t_node **head)
{
	write(1, "ra\n", 3);
	ps_rotate_lst(head);
}

void
	ps_rra(t_node **head)
{
	write(1, "rra\n", 4);
	ps_reverse_rotate_lst(head);
}
