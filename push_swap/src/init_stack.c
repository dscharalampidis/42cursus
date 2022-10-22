/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:57:51 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/22 03:11:58 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node*
	ps_init_stack(t_node *head, int nbr)
{
	head = NULL;
	head = (t_node *)malloc(sizeof(t_node));
	head->nbr = nbr;
	head->nxt = NULL;
	return (head);
}

void
	ps_push_end(t_node *head, int nbr)
{
	t_node	*current;

	current = head;
	while (current->nxt)
		current = current->nxt;
	current->nxt = (t_node *)malloc(sizeof(t_node));
	current->nxt->nbr = nbr;
	current->nxt->nxt = NULL;
}
