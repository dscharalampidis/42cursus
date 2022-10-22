/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/22 03:28:56 by dcharala         ###   ########.fr       */
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
	ps_find_maxpos(t_node *head)
{
	int		i;
	int		max;
	int		max_i;
	t_node *current;

	max = INT_MIN;
	max_i = 1;
	current = head;
	while (current)
	{
		i++;
		if (current->nbr > max)
		{
			max = current->nbr;
			max_i = i;
		}
		current = current->nxt;
	}
	return (max_i);
}

void
	ps_find_shortest_path(int max_i, int lstlen)
{
	if (max_i <= lstlen / 2)
		printf("Access the %dth element top. It will take %d rotation(s).\n", max_i, max_i - 1);
	else
		printf("Access the %dth element of the list from the bottom. It will take %d rotation(s).\n", max_i, lstlen - max_i + 1);
}

int
	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	int		i;
	int		max_i;
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
	max_i = ps_find_maxpos(stack_a);
	printf("max_i: %d\n", max_i);
	ps_find_shortest_path(max_i, lstlen);
	ps_free_list(stack_a);
	return (0);
}
