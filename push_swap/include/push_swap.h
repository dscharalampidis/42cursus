/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:59:33 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/04 17:44:59 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

struct s_node
{
	int				nbr;
	int				idx;
	struct s_node	*nxt;
};

typedef struct s_node	t_node;

/* utils.c */
void	ps_error(void);
void	ps_free(char **arrv, char error);

/* checker.c */
void	ps_chk_invalid_arg(char **arrv);
void	ps_chk_duplicate_arg(char **arrv);
int		ps_chk_nil(char *arr);
char	ps_chk_sorted(int *arr, size_t arrlen);

/* converter.c */
char	**ps_conv_argvtoarrv(char **argv);
size_t	ps_arrlen(char **arrv);
int		*ps_atoi_arr(char **arrv);

/* lst_utils.c */
void	ps_free_lst(t_node **head);
int		ps_find_lst_len(t_node *head);
int		ps_chk_lst_sorted(t_node *head);
int		ps_find_min_i(t_node *head);
t_node	*ps_dup_lst(t_node *head);

/* lst_ops.c */
void	ps_insert_int_lst_head(t_node **head, int nbr, int idx);
void	ps_insert_int_lst_tail(t_node **head, int nbr, int idx);
void	ps_remove_lst_head(t_node **head);
void	ps_remove_lst_tail(t_node **head);

/* lst_rotate.c */
void	ps_rotate_lst(t_node **head);
void	ps_reverse_rotate_lst(t_node **head);
void	ps_ra(t_node **head);
void	ps_rra(t_node **head);

/* lst_push.c */
void	ps_push(t_node **from, t_node **to);
void	ps_pa(t_node **from, t_node **to);
void	ps_pb(t_node **from, t_node **to);

/* lst_swap.c */
void	ps_swap(t_node **head);
void	ps_sa(t_node **head);
void	ps_sb(t_node **head);

/* quicksort.c */
t_node	*qs_find_tail(t_node *head);
t_node	*qs_partition(t_node *start, t_node *end);
void	qs_quicksort(t_node *start, t_node *end);

/* ps_sort.c */
void	ps_index_stack(t_node **unsorted);
void	ps_sort_chunks(t_node **stack_a, t_node **stack_b, int n);
void	ps_sort_two(t_node **head);
void	ps_sort_srp(t_node **stack_a, t_node **stack_b);
void	ps_sort_rp(t_node **stack_a, t_node **stack_b, int min_i, int lstlen);

#endif
