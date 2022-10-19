/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:59:33 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/19 05:38:25 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

/* push_swap.c */
char	**ps_conv_argvtoarr(char **argv);

/* utils.c */
void	ps_error(void);
void	ps_free(char **arrv, char error);

/* checker.c */
void	ps_chk_invalid_arg(char **arrv);
void	ps_chk_duplicate_arg(char **arrv);
int		ps_chk_nil(char *arr);

/* converter.c */
char	**ps_conv_argvtoarrv(char **argv);
size_t	ps_arrlen(char **arrv);
int		*ps_atoi_arr(char **arrv);

#endif
