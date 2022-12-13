# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2022/12/13 03:48:48 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tool macros
CXX := gcc
#CXXFLAGS := -Wall -Wextra -Werror

# path macros
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include
LFT_PATH := libft

# library macros
LFT := libft.a

# compile macros
TARGET := pipex

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
	$(CXX) $(CXXFLAGS) $(OBJ) $(LFT_PATH)/$(LFT) -o $(TARGET)
	@echo "make: *** [pipex] Success"

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
	@rm -f $(CLEAN_LIST)
	@echo "make: *** [pipex] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/

.PHONY: distclean
distclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [pipex] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)

.PHONY: fclean
fclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [pipex] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)

.PHONY: re
re: fclean makedir all
