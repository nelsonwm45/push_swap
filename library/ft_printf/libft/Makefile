# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:14:06 by nchok             #+#    #+#              #
#    Updated: 2024/05/16 16:58:08 by nchok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

AR = ar rcs

SRCS = 	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_bzero.c ft_isascii.c \
		ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_tolower.c \
		ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strnstr.c ft_memchr.c \
		ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_memset.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: .c.o all clean fclean re bonus
