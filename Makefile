# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 13:14:01 by hdagdagu          #+#    #+#              #
#    Updated: 2022/10/18 13:20:47 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf.c \
	ft_put_hex.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_unsi_putnbr.c \
	ft_put_addp.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
AR = ar rcs

all:$(NAME)
	
$(NAME): $(OBJ)
	$(AR) $@ $^

%.o%.c:
	$(CC) $(CFLAGS) -c $^ -o ^@ 

fclean:
	rm -rf $(NAME) $(OBJ)
clean: 
	rm -rf $(OBJ)
re:fclean $(NAME)
