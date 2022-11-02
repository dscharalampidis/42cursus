/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/02 03:18:11 by dcharala         ###   ########.fr       */
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
	t_node	*current;

	i = 0;
	min = INT_MAX;
	min_i = 1;
	current = head;
	while (current)
	{
		++i;
		if (current->nbr < min)
		{
			min = current->nbr;
			min_i = i;
		}
		current = current->nxt;
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
		if (min_i <= lstlen / 2 + 1)
		{
			while (min_i-- - 1)
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

int
	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	int		i;
	/* int		min_i; */
	int		lstlen;
	t_node	*stack_b;

	if (argc > 1)
		arr = ps_parse_arg(argv);
	else
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ps_init_lst(stack_a, arr[0]);
	i = 0;
	while (++i < argc -1)
		ps_insert_int_lst_tail(&stack_a, arr[i]);
	free(arr);
	lstlen = ps_find_lst_len(stack_a);
	/* min_i = ps_find_min(stack_a); */
	if (stack_a->nxt->nbr < stack_a->nbr && lstlen == 2)
		ps_sort_two(&stack_a);
	/* ps_sort_rp(&stack_a, &stack_b, min_i, lstlen); */
	ps_sort_srp(&stack_a, &stack_b, lstlen);
	ps_free_lst(&stack_a);
	return (0);
}
