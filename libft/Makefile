# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2022/10/13 06:22:13 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
			ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c \
			ft_memcpy.c 	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c \
			ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c \
			ft_strncmp.c	ft_strnstr.c \

HEAD	=	libft.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

%.o		:	%.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS) $(HEAD)
			ar r $(NAME) $?
			@echo "make: *** [libft] Success"

clean	:	
			@rm -rf $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
