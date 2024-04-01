# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 12:27:30 by iwaslet           #+#    #+#              #
#    Updated: 2024/03/20 17:48:28 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf_src.c \
		fdf_utils.c \
		fdf_free.c \
		fdf_map_management.c \
		fdf_draw_figure.c \
		fdf_draw_lines.c \
		fdf_calc_lines.c \
		get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -include Libft/libft.h -include minilibx/mlx.h -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	make -C ./Libft
	$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ./minilibx
	make clean -C ./Libft

fclean: clean
	rm -rf $(NAME)
	make clean -C ./minilibx
	make fclean -C ./Libft

debug: CFLAGS += -g -fsanitize=address
debug: re

re: fclean all

.PHONY: all re clean fclean
