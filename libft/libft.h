/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:33:45 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 03:17:36 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int
	ft_isalpha(int chr);
int
	ft_isdigit(int chr);
int
	ft_isalnum(int chr);
int
	ft_isascii(int chr);
int
	ft_isprint(int chr);
size_t
	ft_strlen(const char *str);

#endif
