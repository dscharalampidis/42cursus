/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/24 00:37:11 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_print_list(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	while (current)
	{
		i++;
		printf("list[%d]: %d\n", i, current->nbr);
		current = current->nxt;
	}
}

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
	ps_find_lstlen(t_node *head)
{
	if (!head)
		return (0);
	return (1 + ps_find_lstlen(head->nxt));
}

int
	ps_find_min_pos(t_node *head)
{
	int		i;
	int		min;
	int		min_i;
	t_node *current;

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
	ps_rra(t_node **head_ref, int n)
{
	t_node	*current;
	t_node	*current_tmp;
	int		i;

	if (!n)
		return;
	current = *head_ref;
	i = 0;
	while (++i < n && current)
	{
		current = current->nxt;
		write(1, "rra\n", 3);
	}
	if (!current)
		return;
	current_tmp = current;
	while (current->nxt)
		current = current->nxt;
	current->nxt = *head_ref;
	*head_ref = current_tmp->nxt;
	current_tmp->nxt = NULL;
	write(1, "rra\n", 3);
}

void
	ps_ra(t_node **head_ref, int n)
{
	t_node	*current;
	t_node	*current_tmp;
	int		i;

	if (!n)
		return;
	current = *head_ref;
	i = 0;
	while (++i < n && current)
	{
		current = current->nxt;
		write(1, "ra\n", 3);
	}
	if (!current)
		return;
	current_tmp = current;
	while (current->nxt)
		current = current->nxt;
	current->nxt = *head_ref;
	*head_ref = current_tmp->nxt;
	current_tmp->nxt = NULL;
	write(1, "ra\n", 3);
}

void
	ps_bring_min_to_top(t_node **head, int min_i, int lstlen)
{
	if (min_i <= lstlen / 2 + 1)
	{
		printf("Use ra %d time(s).\n", min_i - 1);
		ps_ra(head, min_i - 1);
	}
	else
	{
		printf("Use rra %d time(s).\n", lstlen - min_i + 1);
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

	if (argc > 1)
		arr = ps_parse_arg(argv);
	else
		return (0);
	stack_a = NULL;
	stack_a = ps_init_stack(stack_a, arr[0]);
	i = 0;
	while (++i < argc -1)
		ps_push_end(stack_a, arr[i]);
	free(arr);
	lstlen = ps_find_lstlen(stack_a);
	printf("lstlen: %d\n", lstlen);
	ps_print_list(stack_a);
	min_i = ps_find_min_pos(stack_a);
	printf("min_i: %d\n", min_i);
	ps_bring_min_to_top(&stack_a, min_i, lstlen);
	ps_print_list(stack_a);
	ps_free_list(stack_a);
	return (0);
}
