# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olkovale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:33:22 by olkovale          #+#    #+#              #
#    Updated: 2018/01/08 10:33:22 by olkovale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBFT_INC = -I./libft/inc
LIBFT_SRC = $(wildcard ./libft/src/*.c)
LIBFT_BIN = $(patsubst ./libft/src/*.c %.o, $(LIBFT_SRC))
BISTRO = ./bistromatic
BISTRO_INC = -I./libft/inc -I./bistro/inc
BISTRO_SRC = $(wildcard ./bistro/src/*.c)
BISTRO_BIN = $(patsubst ./bistro/src/*.c %.o, $(BISTRO_SRC))

.PHONY: re all clean fclean

all: $(BISTRO)

$(BISTRO): $(LIBFT) $(BISTRO_BIN)
	$(CC) $(FLAGS) $(LIBFT) $(BISTRO_BIN) -o $(BISTRO)

$(LIBFT): $(LIBFT_BIN)
	$(CC) $(FLAGS) $(LIBFT_BIN) -o $(LIBFT)

bistro/src/%.o : bistro/src/%.c bistro/inc/bistro.h
	$(CC) $(BISTRO_INC) $(FLAGS) -c $<

libft/src/%.o : libft/src/%.c libft/inc/libft.h
	$(CC) $(LIBFT_INC) $(FLAGS) -c $<

clean:
	make clean -C ./libft
	make clean -C ./bistromatic

fclean:
	make fclean -C ./libft
	make fclean -C ./bistromatic

re: fclean all
