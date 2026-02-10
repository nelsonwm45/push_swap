# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 14:54:47 by nchok             #+#    #+#              #
#    Updated: 2024/05/27 18:20:16 by nchok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

GNL_HEADER = get_next_line/get_next_line_bonus.h

SRCS = ft_number.c \
		ft_string.c \
		ft_printf.c \

GNL_DIR	=	get_next_line/
SRCS_GNL	=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \

OBJS = $(SRCS:.c=.o) \
		$(addprefix $(GNL_DIR), $(SRCS_GNL:.c=.o))

FLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

AR = ar rcs

all: $(NAME)


$(NAME): $(OBJS)
	@make -s -C libft/
	@make bonus -s -C libft/
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
# $(CC) $(CFLAGS) main.c $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)%.o : $(GNL_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean: clean
	@make  fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: .c all clean fclean re
