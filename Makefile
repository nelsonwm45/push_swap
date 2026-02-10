# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 17:51:20 by nchok             #+#    #+#              #
#    Updated: 2024/05/23 18:50:31 by nchok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

NAME = push_swap
NAME_BONUS = checker
HEADER = -I header/push_swap.h
HEADER_BONUS = -I header/push_swap_bonus.h

LIBFTPRINTF = library/ft_printf/libftprintf.a
SRC_DIR = src/
SRC_DIR_BONUS = src_bonus/
OBJ_DIR = obj/
OBJ_DIR_BONUS = obj_bonus/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANTIZE = -fsanitize=address -g3
RM = rm -f
AR = ar rcs

SRC_FILES	=	push.c \
				rev_rotate.c \
				rotate.c \
				swap.c \
				handle_error.c \
				wordsplit.c \
				stack_utils.c \
				stack_init.c \
				stack_utils2.c \
				radix_sort.c \
				simple_sort.c

SRC_MAIN	= $(addprefix $(SRC_DIR), main.c)

SRC_FILES_BONUS	=	push_bonus.c \
					rev_rotate_bonus.c \
					rotate_bonus.c \
					swap_bonus.c \
					handle_error_bonus.c \
					wordsplit_bonus.c \
					stack_utils_bonus.c \
					stack_init_bonus.c \
					stack_utils2_bonus.c \
					parsing_utils_bonus.c \
					parsing_bonus.c \

SRC_MAIN_BONUS = $(addprefix $(SRC_DIR_BONUS), checker.c)

OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

OBJ_FILES_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(SRC_FILES_BONUS:.c=.o))

# SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_SUPPORT)) \
# 			$(addprefix $(SRC_DIR)stack_op/, $(SRC_STACK_OP))

# OBJ_STACK_OP = $(addprefix $(OBJ_DIR), $(SRC_STACK_OP:.c=.o))
# OBJ_SUPPORT = $(addprefix $(OBJ_DIR), $(SRC_SUPPORT:.c=.o))

# OBJ_FILES = $(OBJ_STACK_OP) $(OBJ_SUPPORT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR_BONUS)%.o : $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) $(HEADER_BONUS) -c $< -o $@

start : $(OBJ_DIR)
	@echo $(CYAN)"\n----------COMPILING FILES----------\n"$(CYAN)
	@make -s -C ./library/ft_printf
	@cp $(LIBFTPRINTF) $(OBJ_DIR)
	@make -s all

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS) :
	@mkdir -p $(OBJ_DIR_BONUS)

all : $(NAME)

# $(OBJ_FILES)%.o : $(SRC_FILES)%.c
# 	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME) : $(OBJ_FILES) | $(OBJ_DIR)
	@$(AR) $(LIBFTPRINTF) $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(HEADER) $(LIBFTPRINTF) $(SRC_MAIN) -o $(NAME)
	@echo $(GREEN)"\n----------FILES COMPILED SUCCESSFULLY----------\n"$(GREEN)
	@echo $(CYAN)"\nProgram Name is"$(CYAN) $(BLUE)"$(NAME)\n"$(BLUE)

bonus : $(OBJ_FILES_BONUS) | $(OBJ_DIR_BONUS)
	@echo $(BLUE)"\n----------SQUEEZING BONUS OUT----------\n"$(BLUE)
	@make -s -C ./library/ft_printf
	@cp $(LIBFTPRINTF) $(OBJ_DIR_BONUS)
	@$(AR) $(LIBFTPRINTF) $(OBJ_FILES_BONUS)
	@$(CC) $(CFLAGS) $(HEADER_BONUS) $(LIBFTPRINTF) $(SRC_MAIN_BONUS) -o $(NAME_BONUS)
	@echo $(GREEN)"\n----------BABY BONUS IS OUT----------\n"$(GREEN)
	@echo $(CYAN)"\nProgram Name is"$(CYAN) $(BLUE)"$(NAME_BONUS)\n"$(BLUE)

clean :
	@echo $(BLUE)"\n----------CLEANING IN PROGRESS----------\n"$(BLUE)
	@make fclean -C library/ft_printf
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo $(GREEN)"\n----------SUCCESSFULLY CLEANED----------\n"$(GREEN)

fclean : clean
	@$(RM) -r $(OBJ_DIR_BONUS)
	@$(RM) $(NAME_BONUS)

re : fclean start

.PHONY: start all clean fclean re
