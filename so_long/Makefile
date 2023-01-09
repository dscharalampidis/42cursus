# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2023/01/09 22:21:52 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# install brew at 42
# rm -rf $HOME/goinfre/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

# tool macros
CXX := gcc
CXXFLAGS := -Wall -Wextra -Werror

# path macros
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include
LFT_PATH := libft
MLX_PATH := MLX42


# library macros
LFT := libft.a
MLX := libmlx42.a
ifeq ($(shell uname), Darwin)
MLXFLAGS := -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"
endif
ifeq ($(shell uname), Linux)
MLXFLAGS := -ldl -lglfw -pthread -lm
endif

# compile macros
TARGET := so_long

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
	@make -C $(MLX_PATH)
	@echo "make: *** [mlx] Success"
	$(CXX) $(OBJ) $(LFT_PATH)/$(LFT) $(MLX_PATH)/$(MLX) $(MLXFLAGS) $(CXXFLAGS) -o $(TARGET)
	@echo "make: *** [so_long] Success"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CXX) $(CXXFLAGS) -I$(INC_PATH) -I$(MLX_PATH)/$(INC_PATH) -c $< -o $@

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@rm -f $(CLEAN_LIST)
	@echo "make: *** [so_long] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/
	@make clean -C $(MLX_PATH)/
	@echo "make: *** [mlx] Cleaned" $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [so_long] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)
	@make fclean -C $(MLX_PATH)/
	@echo "make: *** [mlx] Cleaned" $(CLEAN_LIST)

.PHONY: fclean
fclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [so_long] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)
	@make fclean -C $(MLX_PATH)/
	@echo "make: *** [mlx] Cleaned" $(CLEAN_LIST)

.PHONY: re
re: fclean makedir all
