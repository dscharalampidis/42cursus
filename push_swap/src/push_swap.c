/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/01 17:08:13 by dcharala         ###   ########.fr       */
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

int
	ps_chk_lst_sorted(t_node *head)
{
	if (head == NULL)
		return 0;
	while (head->nxt)
	{
		if (head->nbr > head->nxt->nbr)
			return 1;
		head = head->nxt;
	}
	return 0;
}

/* Find the minimum and find the fastest path to bring it to top by rotating or
 * reverse rotating. While rotating check if the second to top number is smaller
 * than the top and swap them. Keep doing this and when the minimum is at the
 * top, push it to stack B. Finally, push everything back to A. */
void
	ps_trytosort(t_node **stack_a, t_node **stack_b, int min_i, int lstlen)
{
	while (ps_chk_lst_sorted(*stack_a) != 0 && *stack_a)
	{
		if ((*stack_a)->nxt->nbr < (*stack_a)->nbr)
		{
			printf("sa\n");
			ps_swap(stack_a);
			min_i = ps_find_min_pos(*stack_a);
			/* printf("--- Stack A ---\n"); */
			/* ps_print_lst(*stack_a); */
			/* printf("--- Stack B ---\n"); */
			/* ps_print_lst(*stack_b); */
		}
		if (min_i != 1 && min_i <= lstlen / 2 + 1)
		{	
			printf("ra\n");
			ps_rotate_lst(stack_a);
			min_i = ps_find_min_pos(*stack_a);
			/* printf("--- Stack A ---\n"); */
			/* ps_print_lst(*stack_a); */
			/* printf("--- Stack B ---\n"); */
			/* ps_print_lst(*stack_b); */
		}
		else if (min_i != 1 && min_i > lstlen / 2 + 1)
		{
			printf("rra\n");
			ps_reverse_rotate_lst(stack_a);
			min_i = ps_find_min_pos(*stack_a);
			/* printf("--- Stack A ---\n"); */
			/* ps_print_lst(*stack_a); */
			/* printf("--- Stack B ---\n"); */
			/* ps_print_lst(*stack_b); */
		}
		else
		{
			printf("pb\n");
			ps_push(stack_a, stack_b);
			lstlen = ps_find_lst_len(*stack_a);
			min_i = ps_find_min_pos(*stack_a);
			/* printf("--- Stack A ---\n"); */
			/* ps_print_lst(*stack_a); */
			/* printf("--- Stack B ---\n"); */
			/* ps_print_lst(*stack_b); */
		}
	}
}

/* Find the minimum, find the fastest path to bring it to top by rotating or
 * reverse rotating and then push it to stack B. Finally, push everything back
 * to A. */
void
	ps_sort_ins(t_node **stack_a, t_node **stack_b,  int min_i, int lstlen)
{
	int	i;

	while (ps_chk_lst_sorted(*stack_a) != 0 && stack_a)
	{
		if (min_i <= lstlen / 2 + 1)
		{
			/* printf("Use ra %d time(s).\n", min_i - 1); */
			while (min_i-- - 1)
			{
				printf("ra\n");
				ps_rotate_lst(stack_a);
			}
		}
		else
		{
			/* printf("Use rra %d time(s).\n", lstlen - min_i + 1); */
			i = lstlen - min_i + 1;
			while (i--)
			{
				printf("rra\n");
				ps_reverse_rotate_lst(stack_a);
			}
		}
		printf("pb\n");
		ps_push(stack_a, stack_b);
		lstlen = ps_find_lst_len(*stack_a);
		min_i = ps_find_min_pos(*stack_a);
	}
}

void
	ps_backtoa(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
	{
		printf("pa\n");
		ps_push(stack_b, stack_a);
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
	/* printf("--- Original Stack A ---\n"); */
	/* ps_print_lst(stack_a); */
	min_i = ps_find_min_pos(stack_a);
	/* printf("min_i: %d\n", min_i); */
	if (stack_a->nxt->nbr < stack_a->nbr && lstlen == 2)
	{
		printf("sa\n");
		ps_swap(&stack_a);
		return (0);
	}
	ps_sort_ins(&stack_a, &stack_b, min_i, lstlen);
	/* ps_trytosort(&stack_a, &stack_b, min_i, lstlen); */
	/* printf("--- Stack A ---\n"); */
	/* ps_print_lst(stack_a); */
	/* printf("--- Stack B ---\n"); */
	/* ps_print_lst(stack_b); */
	ps_backtoa(&stack_a, &stack_b);
	/* printf("--- Stack A ---\n"); */
	/* ps_print_lst(stack_a); */
	/* printf("--- Stack B ---\n"); */
	/* ps_print_lst(stack_b); */
	/* printf("%d\n", ps_chk_lst_sorted(stack_a)); */
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
