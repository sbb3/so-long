# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouib <adouib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 16:09:46 by adouib            #+#    #+#              #
#    Updated: 2022/02/06 15:43:08 by adouib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I../incl/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFTPATH = ./srcs/libft/libft.a

RM = rm -rf

SRCS = ./srcs/so_long.c \
	./srcs/parsing.c \
	./srcs/checks.c \
	./srcs/rendering.c \
	./srcs/player_move.c \
	./srcs/tools.c \
	./srcs/quit.c \
	./srcs/gnl/get_next_line.c

OBJS = $(SRCS:%.c=%.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./srcs/libft/
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFTPATH) -o $(NAME)

./srcs/%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJS)
	@$(RM) ./srcs/libft/*.o
	@make clean -C ./srcs/libft/

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./srcs/libft/

re: fclean all
