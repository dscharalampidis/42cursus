/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:33:45 by dcharala          #+#    #+#             */
/*   Updated: 2022/10/13 07:28:04 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdint.h>

int			ft_isalpha(int chr);
int			ft_isdigit(int chr);
int			ft_isalnum(int chr);
int			ft_isascii(int chr);
int			ft_isprint(int chr);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *buf, int chr, size_t len);
void		ft_bzero(void *ptr, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t siz);
size_t		ft_strlcat(char *dst, const char *src, size_t siz);
int			ft_toupper(int chr);
int			ft_tolower(int chr);
char		*ft_strchr(const char *ptr, int chr);
char		*ft_strrchr(const char *ptr, int chr);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);

#endif
