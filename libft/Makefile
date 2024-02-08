# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:21:46 by hskikdi           #+#    #+#              #
#    Updated: 2021/08/17 20:16:46 by hskikdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ = \
	  ft_putstr_fd.o \
	  ft_split.o \
	  ft_strdup.o \
	  ft_strjoin.o \
	  ft_strlen.o \
	  ft_strncmp.o \
	  ft_arrfree.o \
	  ft_memdel.o \
	  ft_putendl_fd.o \
	  ft_putnbr_fd.o \
	  ft_atoi.o \
	  ft_strdel.o

FLAG = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar -rsc $(NAME) $(OBJ)

%.o:%.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
