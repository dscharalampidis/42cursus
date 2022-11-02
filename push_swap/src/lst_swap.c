/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:28:52 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/02 02:32:26 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_swap(t_node **head)
{
	int	tmp1;
	int	tmp2;

	tmp1 = (*head)->nbr;
	tmp2 = (*head)->nxt->nbr;
	ps_remove_lst_head(head);
	ps_remove_lst_head(head);
	ps_insert_int_lst_head(head, tmp1);
	ps_insert_int_lst_head(head, tmp2);
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
