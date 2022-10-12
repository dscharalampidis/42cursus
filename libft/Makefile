# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2022/10/13 01:51:46 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalpha.c

HEAD	=	libft.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

%.o		:	%.c $(HEAD)
			@echo ""
			@echo "[COMPILATION STARTED]"
			@echo ""
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS) $(HEAD)
			ar r $(NAME) $?
			@echo ""
			@echo "[COMPILATION COMPLETED]"
			@echo ""

clean	:	
			@rm -rf $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
