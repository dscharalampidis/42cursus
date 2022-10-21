/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:10:03 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/21 23:41:19 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_push_end(t_node *head, int nbr)
{
	t_node	*current;

	current = head;
	while (current->nxt != NULL)
		current = current->nxt;
	current->nxt = (t_node *)malloc(sizeof(t_node));
	current->nxt->nbr = nbr;
	current->nxt->nxt = NULL;
}

void
	ps_print_list(t_node *head)
{
	t_node 	*current;

	current = head;
	while (current != NULL)
	{
		printf("list: %d\n", current->nbr);
		current = current->nxt;
	}
}

void
	ps_free_list(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->nxt;
		free(tmp);
	}
}

t_node*
	ps_init_stack(t_node *head, int nbr)
{
	head = NULL;
	head = (t_node *)malloc(sizeof(t_node));
	head->nbr = nbr;
	head->nxt = NULL;
	return (head);
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
	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	int		i;

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
	ps_print_list(stack_a);
	ps_free_list(stack_a);
	return (0);
}
