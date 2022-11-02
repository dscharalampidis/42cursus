/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:59:33 by dcharala          #+#    #+#             */
/*   Updated: 2022/11/02 21:38:00 by dcharala         ###   ########.fr       */
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

/* push_swap.c */
char	**ps_conv_argvtoarr(char **argv);

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
t_node	*ps_init_lst(t_node *head, int nbr);
void	ps_free_lst(t_node **head);
int		ps_find_lst_len(t_node *head);
void	ps_print_lst(t_node *head);
int		ps_chk_lst_sorted(t_node *head);

/* lst_ops.c */
void	ps_insert_int_lst_head(t_node **head, int nbr);
void	ps_insert_int_lst_tail(t_node **head, int nbr);
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

#endif
