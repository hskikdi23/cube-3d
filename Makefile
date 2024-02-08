# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 22:10:48 by hskikdi           #+#    #+#              #
#    Updated: 2022/05/11 22:10:50 by hskikdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ=$(addsuffix .o, ft_draw raycasting_calculs ft_raycasting init_utils move_player rotate_player quit_game handle_key extend_map checker_map checker_map_utils file_reader parser_map fill_parse init main parser color_parse parser_utiles get_next_line get_next_line_utils)

NAME=cub3d

FLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAG) $^ -o $@ libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAG) -c -o $@ $< -Iincludes

clean:
	make clean -C libft
	make clean -C minilibx_macos
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C minilibx_macos

re: fclean all
