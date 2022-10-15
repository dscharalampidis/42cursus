/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:47:14 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/15 06:18:05 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifdef __linux__
#  ifndef OS_FLAG
#   define OS_FLAG 'L'
#  endif
# endif

/* ft_printf.c */
int		ft_printf(const char *fmt, ...);
void	pf_get_specifiers(va_list ap, char *fmt, int *nbytes);
int		pf_distribute_conversion(char specifier, va_list ap);

/* pf_convert_chr.c */
int		pf_convert_chr(va_list ap);

/* pf_convert_str.c */
int		pf_convert_str(va_list ap);

/* pf_convert_nbr.c */
int		pf_convert_nbr(va_list ap, char specifier);
int		pf_get_nbr_len(long int n);
void	pf_putnbr(long int n);

/* pf_convert_hex.c */
int		pf_convert_hex(va_list ap, char specifier);
int		pf_convert_ptr(va_list ap);
int		pf_get_hex_len(unsigned long long n);
void	pf_puthex(unsigned long long n, char specifier);

#endif
