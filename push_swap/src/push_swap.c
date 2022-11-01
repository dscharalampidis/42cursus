/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/31 22:25:11 by dcharala         ###   ########.fr       */
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
	ps_trytosort(t_node **stack_a, t_node **stack_b, int min_i, int lstlen)
{
	while (min_i != 1 && *stack_a)
	{
		if ((*stack_a)->nxt->nbr < (*stack_a)->nbr)
		{
			printf("sa\n");
			ps_swap(stack_a);
			min_i = ps_find_min_pos(*stack_a);
			printf("new min_i: %d\n", min_i);
		}
		if (min_i != 1 && min_i <= lstlen / 2 + 1)
		{	
			printf("ra\n");
			ps_rotate_lst(stack_a);
		}
		else if (min_i != 1 && min_i > lstlen / 2 + 1)
		{
			printf("rra\n");
			ps_reverse_rotate_lst(stack_a);
		}
		else
		{
			printf("pb\n");
			ps_push(stack_a, stack_b);
			lstlen = ps_find_lst_len(*stack_a);
			min_i = ps_find_min_pos(*stack_a);
		}
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
	printf("--- Stack A ---\n");
	ps_print_lst(stack_a);
	min_i = ps_find_min_pos(stack_a);
	printf("min_i: %d\n", min_i);
	ps_trytosort(&stack_a, &stack_b, min_i, lstlen);
	printf("--- Stack A ---\n");
	ps_print_lst(stack_a);
	printf("--- Stack B ---\n");
	ps_print_lst(stack_b);
/* printf("Push from A to B\n"); */
	/* ps_push(&stack_a, &stack_b); */
	/* printf("Printing stack B\n"); */
	/* ps_print_lst(stack_b); */
	/* printf("Deleting the first node\n"); */
	/* ps_remove_lst_head(&stack_a); */
	/* ps_print_lst(stack_a); */
	/* printf("Swapping the top two nodes...\n"); */
	/* ps_swap(&stack_a); */
	/* ps_print_lst(stack_a); */
	ps_free_lst(&stack_a);
	return (0);
}
