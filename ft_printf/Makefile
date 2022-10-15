# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2022/10/15 05:44:20 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tool macros
CXX := gcc
CXXFLAGS := -Wall -Wextra -Werror

# path macros
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include
LFT_PATH := libft

# compile macros
TARGET := libftprintf.a

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ) \
CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	@make -C $(LFT_PATH)
	@cp $(LFT_PATH)/libft.a .
	@mv libft.a $(TARGET)
	@ar rcs $(TARGET) $(OBJ)
	@echo "make: *** [ft_printf] Success"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CXX) $(CXXFLAGS) -I$(INC_PATH) -c $< -o $@

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@echo "make: *** [ft_printf] Cleaned" $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/

.PHONY: distclean
distclean:
	@echo "make: *** [ft_printf] Cleaned" $(CLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/libft.a

.PHONY: fclean
fclean:
	@echo "make: *** [ft_printf] Cleaned" $(CLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/libft.a

.PHONY: re
re: fclean makedir all
