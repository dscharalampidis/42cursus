/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:35:08 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 01:44:29 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_push(t_node **from, t_node **to)
{
	ps_insert_int_lst_head(to, (*from)->nbr, (*from)->idx);
	ps_remove_lst_head(from);
}

void
	ps_pa(t_node **from, t_node **to)
{
	write(1, "pa\n", 3);
	ps_push(from, to);
}

void
	ps_pb(t_node **from, t_node **to)
{
	write(1, "pb\n", 3);
	ps_push(from, to);
}
