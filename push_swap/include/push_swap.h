/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:59:33 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/22 00:00:32 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_node
{
	int				nbr;
	struct s_node	*nxt;
}					t_node;

/* push_swap.c */
char	**ps_conv_argvtoarr(char **argv);

/* utils.c */
void	ps_error(void);
void	ps_free(char **arrv, char error);
void	ps_free_list(t_node *head);

/* checker.c */
void	ps_chk_invalid_arg(char **arrv);
void	ps_chk_duplicate_arg(char **arrv);
int		ps_chk_nil(char *arr);
char	ps_chk_sorted(int *arr, size_t arrlen);

/* converter.c */
char	**ps_conv_argvtoarrv(char **argv);
size_t	ps_arrlen(char **arrv);
int		*ps_atoi_arr(char **arrv);

/* init_stack.c */
t_node	*ps_init_stack(t_node *head, int nbr);
void	ps_push_end(t_node *head, int nbr);

#endif
