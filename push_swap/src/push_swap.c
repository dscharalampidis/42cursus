/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/04 18:00:01 by dcharala         ###   ########.fr       */
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

void
	ps_dist_sort(t_node *stack_a, t_node *stack_b)
{
	int	min_i;
	int	lstlen;

	lstlen = ps_find_lst_len(stack_a);
	if (stack_a->nxt->nbr < stack_a->nbr && lstlen == 2)
		ps_sort_two(&stack_a);
	if (lstlen > 2 && lstlen < 10)
	{
		ps_sort_srp(&stack_a, &stack_b);
		exit (EXIT_SUCCESS);
	}
	ps_index_stack(&stack_a);
	if (lstlen >= 10 && lstlen <= 100)
		ps_sort_chunks(&stack_a, &stack_b, 6);
	else
		ps_sort_chunks(&stack_a, &stack_b, 13);
	min_i = ps_find_min_i(stack_a);
	ps_sort_rp(&stack_a, &stack_b, min_i, lstlen);
	ps_free_lst(&stack_a);
	ps_free_lst(&stack_b);
}

int
	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

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
	ps_dist_sort(stack_a, stack_b);
	return (0);
}
