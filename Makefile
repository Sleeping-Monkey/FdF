# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnesoi <bnesoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 15:11:22 by bnesoi            #+#    #+#              #
#    Updated: 2019/04/26 10:39:49 by bnesoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

OS:=$(shell uname -s)
SRC:=$(shell find src/ -maxdepth 1 -type f -regex ".*\.c" -printf "%P\n")
LIBFT=./libft/libft.a
LIBFT_DIR=./libft
INC_DIR=./includes
OBJ_DIR=./obj
SRC_DIR=./src
ifeq ($(OS),Linux)
    MINILIBX_DIR=./minilibx
    MINILIBX_LINK=-L$(MINILIBX_DIR) -lXext -lX11 -lmlx
else
    MINILIBX_DIR=./minilibx_macos
    MINILIBX_LINK=-L$(MINILIBX_DIR) -framework OpenGL -framework AppKit -lmlx
endif
MINILIBX=$(MINILIBX_DIR)/libmix.a

CC=gcc
CC_FLAGS=-Wall -Wextra -Werror

OBJ=$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBS=-lm -lft $(MINILIBX_LINK)

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MINILIBX_DIR) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)/ --no-print-directory

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)/ --no-print-directory

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	@$(CC)  $(CC_FLAGS) -L$(LIBFT_DIR) $(OBJ) $(LIBS) -o ${NAME};

clean :
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(info $(OS))$(LIBFT_DIR) --no-print-directory
	@make clean -C $(MINILIBX_DIR) --no-print-directory

fclean : clean
	@/bin/rm -f $(NAME) $(addprefix tests/test_,$(FILE_NAMES))
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@/bin/rm -f ${MINILIBX}
	@/bin/rm -f $(addprefix tests/,$(TEST_NAMES))

re : fclean all


TEST_NAMES=\
	test_ft_printf_di

test-all:
	@for s in $(TEST_NAMES) ; do \
		if [ -f tests/$$s.c ]; then \
			$(MAKE) test name=$$s --no-print-directory;\
		fi; \
	done

test: all
	@gcc  $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -L. tests/$(name).c -lftprintf -o tests/$(name);
	$(info ************ $(name))
