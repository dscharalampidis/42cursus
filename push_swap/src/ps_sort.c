/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:18:06 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/04 18:05:57 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_index_stack(t_node **unsorted)
{
	int		i;
	t_node	*sorted;
	t_node	*sorted_head;
	int		trick;

	trick = (*unsorted)->nbr;
	sorted = ps_dup_lst(*unsorted);
	sorted_head = sorted;
	qs_quicksort(sorted, qs_find_tail(sorted));
	i = 1;
	while (sorted)
	{
		if (sorted->nbr == (*unsorted)->nbr)
		{
			(*unsorted)->idx = i;
			sorted = sorted->nxt;
			i++;
		}
		else
			ps_rotate_lst(unsorted);
	}
	ps_free_lst(&sorted_head);
	while ((*unsorted)->nbr != trick)
		ps_rotate_lst(unsorted);
}

void
	ps_sort_chunks(t_node **stack_a, t_node **stack_b, int n)
{
	int	chunk_size;
	int	i;
	int	j;

	chunk_size = ps_find_lst_len(*stack_a) / n;
	i = 0;
	while (++i <= n)
	{
		j = chunk_size;
		while (j)
		{
			if ((*stack_a)->idx <= chunk_size * i)
			{
				j--;
				ps_pb(stack_a, stack_b);
			}
			else
				ps_ra(stack_a);
		}
	}
	while (*stack_b)
		ps_pa(stack_b, stack_a);
}

/* Just swap. It's the fastest for two numbers. */
void
	ps_sort_two(t_node **head)
{
	ps_sa(head);
	exit(EXIT_SUCCESS);
}

/* Find the minimum and find the fastest path to bring it to top by rotating or
 * reverse rotating. While rotating check if the second to top number is smaller
 * than the top and swap them. Keep doing this and when the minimum is at the
 * top, push it to stack B. Finally, push everything back to A. It's the fastest
 * for less than 10 numbers. */
void
	ps_sort_srp(t_node **stack_a, t_node **stack_b)
{
	int	lstlen;

	lstlen = ps_find_lst_len(*stack_a);
	while (!ps_chk_lst_sorted(*stack_a))
	{
		if ((*stack_a)->nxt->nbr < (*stack_a)->nbr)
			ps_sa(stack_a);
		if (ps_find_min_i(*stack_a) != 1
			&& ps_find_min_i(*stack_a) <= lstlen / 2 + 1)
			ps_ra(stack_a);
		else if (ps_find_min_i(*stack_a) != 1
			&& ps_find_min_i(*stack_a) > lstlen / 2 + 1)
			ps_rra(stack_a);
		else
		{
			ps_pb(stack_a, stack_b);
			lstlen = ps_find_lst_len(*stack_a);
		}
	}
	while (*stack_b)
		ps_pa(stack_b, stack_a);
}

/* Find the minimum, find the fastest path to bring it to top by rotating or
 * reverse rotating and then push it to stack B. Finally, push everything back
 * to A. It requires long lists to be organised in chunks, but after that it's
 * faster than the srp algo above. */
void
	ps_sort_rp(t_node **stack_a, t_node **stack_b, int min_i, int lstlen)
{
	int	i;

	while (!ps_chk_lst_sorted(*stack_a))
	{
		if (!min_i)
			ps_pb(stack_a, stack_b);
		else if (min_i <= lstlen / 2 + 1)
		{
			while (min_i-- -1)
				ps_ra(stack_a);
		}
		else
		{
			i = lstlen - min_i + 1;
			while (i--)
				ps_rra(stack_a);
		}
		ps_pb(stack_a, stack_b);
		lstlen = ps_find_lst_len(*stack_a);
		min_i = ps_find_min_i(*stack_a);
	}
	while (*stack_b)
		ps_pa(stack_b, stack_a);
}
