/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/30 21:48:34 by dcharala         ###   ########.fr       */
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
	ps_find_min_pos(t_node *head)
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

void
	ps_bring_min_to_top(t_node **head, int min_i, int lstlen)
{
	int	i;

	if (min_i <= lstlen / 2 + 1)
	{
		printf("Use ra %d time(s).\n", min_i - 1);
		while (min_i-- - 1)
			ps_rotate_lst(head);
	}
	else
	{
		printf("Use rra %d time(s).\n", lstlen - min_i + 1);
		i = lstlen - min_i + 1;
		while (i--)
			ps_reverse_rotate_lst(head);
	}
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
	stack_a = ps_init_lst(stack_a, arr[0]);
	i = 0;
	while (++i < argc -1)
		ps_insert_int_lst_tail(&stack_a, arr[i]);
	free(arr);
	lstlen = ps_find_lst_len(stack_a);
	printf("lstlen: %d\n", lstlen);
	ps_print_lst(stack_a);
	min_i = ps_find_min_pos(stack_a);
	printf("min_i: %d\n", min_i);
	ps_bring_min_to_top(&stack_a, min_i, lstlen);
	ps_print_lst(stack_a);
	printf("Push from A to B\n");
	ps_push(&stack_a, &stack_b);
	printf("Printing stack B\n");
	ps_print_lst(stack_b);
	printf("Deleting the first node\n");
	ps_remove_lst_head(&stack_a);
	ps_print_lst(stack_a);
	ps_free_lst(&stack_a);
	return (0);
}
