/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:28:52 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 02:28:40 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_swap(t_node **head)
{
	int	nbr1;
	int	idx1;
	int	nbr2;
	int	idx2;

	nbr1 = (*head)->nbr;
	idx1 = (*head)->idx;
	nbr2 = (*head)->nxt->nbr;
	idx2 = (*head)->nxt->idx;
	ps_remove_lst_head(head);
	ps_remove_lst_head(head);
	ps_insert_int_lst_head(head, nbr1, idx1);
	ps_insert_int_lst_head(head, nbr2, idx2);
}

void
	ps_sa(t_node **head)
{
	write(1, "sa\n", 3);
	ps_swap(head);
}

void
	ps_sb(t_node **head)
{
	write(1, "sb\n", 3);
	ps_swap(head);
}
