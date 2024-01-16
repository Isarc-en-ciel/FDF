# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 12:27:30 by iwaslet           #+#    #+#              #
#    Updated: 2024/01/08 16:04:21 by iwaslet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf_src.c \
		fdf_utils.c \
		get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	cp ./minilibx/libmlx.a $(NAME)
	make -C ./Libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ./minilibx
	make clean -C ./Libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./minilibx
	make fclean -C ./Libft

re: fclean all

.PHONY: all re clean fclean
