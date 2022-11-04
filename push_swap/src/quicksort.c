/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:40:57 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 12:52:18 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node*
	qs_find_tail(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp && tmp->nxt)
		tmp = tmp->nxt;
	return (tmp);
}

t_node*
	qs_partition(t_node *start, t_node *end)
{
	t_node	*pivot;
	t_node	*front;
	int		tmp;

	pivot = start;
	front = start;
	tmp = 0;
	while (front && front != end)
	{
		if (front->nbr < end->nbr)
		{
			pivot = start;
			tmp = start->nbr;
			start->nbr = front->nbr;
			front->nbr = tmp;
			start = start->nxt;
		}
		front = front->nxt;
	}
	tmp = start->nbr;
	start->nbr = end->nbr;
	end->nbr = tmp;
	return (pivot);
}

void
	qs_quicksort(t_node *start, t_node *end)
{
	t_node	*pivot;

	if (start == end)
		return ;
	pivot = qs_partition(start, end);
	if (pivot && pivot->nxt)
		qs_quicksort(pivot->nxt, end);
	if (pivot && start != pivot)
		qs_quicksort(start, pivot);
}
