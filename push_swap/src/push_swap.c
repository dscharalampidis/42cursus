/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/03 12:49:36 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int*
	ps_parse_arg(char **argv)
{
	char	**arrv;
	int		*arr;
	size_t	arrlen;
	char	sorted;

	arrv = NULL;
	arrv = ps_conv_argvtoarrv(argv);
	ps_chk_invalid_arg(arrv);
	ps_chk_duplicate_arg(arrv);
	arr = ps_atoi_arr(arrv);
	arrlen = ps_arrlen(arrv);
	sorted = ps_chk_sorted(arr, arrlen);
	if (sorted == 'Y')
	{
		ps_free(arrv, 'N');
		free(arr);
		exit (EXIT_SUCCESS);
	}
	ps_free(arrv, 'N');
	return (arr);
}

int
	ps_find_min(t_node *head)
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

/* Find the minimum and find the fastest path to bring it to top by rotating or
 * reverse rotating. While rotating check if the second to top number is smaller
 * than the top and swap them. Keep doing this and when the minimum is at the
 * top, push it to stack B. Finally, push everything back to A. */
void
	ps_sort_srp(t_node **stack_a, t_node **stack_b, int lstlen)
{
	while (!ps_chk_lst_sorted(*stack_a))
	{
		if ((*stack_a)->nxt->nbr < (*stack_a)->nbr)
			ps_sa(stack_a);
		if (ps_find_min(*stack_a) != 1
			&& ps_find_min(*stack_a) <= lstlen / 2 + 1)
			ps_ra(stack_a);
		else if (ps_find_min(*stack_a) != 1
			&& ps_find_min(*stack_a) > lstlen / 2 + 1)
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
 * to A. */
void
	ps_sort_rp(t_node **stack_a, t_node **stack_b, int min_i, int lstlen)
{
	int	i;

	while (!ps_chk_lst_sorted(*stack_a))
	{
		if (!min_i)
			ps_pb(stack_a, stack_b);
		if (min_i <= lstlen / 2 + 1)
		{
			while (min_i---1)
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
		min_i = ps_find_min(*stack_a);
	}
	while (*stack_b)
		ps_pa(stack_b, stack_a);
}

void
	ps_sort_two(t_node **head)
{
	ps_sa(head);
	exit(EXIT_SUCCESS);
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
			if ((*stack_a)->idx <= chunk_size * i)
			{
				j--;
				ps_pb(stack_a, stack_b);
			}
			else
				ps_ra(stack_a);
	}
	while (*stack_b)
		ps_pa(stack_b, stack_a);
}

int
	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	int		i;
	int		min_i;
	int		lstlen;
	t_node	*stack_b;

	if (argc > 1)
		arr = ps_parse_arg(argv);
	else
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	while (++i < argc -1)
		ps_insert_int_lst_tail(&stack_a, arr[i], 0);
	free(arr);
	lstlen = ps_find_lst_len(stack_a);
	if (stack_a->nxt->nbr < stack_a->nbr && lstlen == 2)
		ps_sort_two(&stack_a);
	if (lstlen > 2 && lstlen < 10)
	{
		ps_sort_srp(&stack_a, &stack_b, lstlen);
		exit (EXIT_SUCCESS);
	}
	ps_index_stack(&stack_a);
	if (lstlen >= 10 && lstlen <= 100)
		ps_sort_chunks(&stack_a, &stack_b, 6);
	else
		ps_sort_chunks(&stack_a, &stack_b, 13);
	min_i = ps_find_min(stack_a);
	ps_sort_rp(&stack_a, &stack_b, min_i, lstlen);
	ps_free_lst(&stack_a);
	ps_free_lst(&stack_b);
	return (0);
}
