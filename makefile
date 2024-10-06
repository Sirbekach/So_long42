# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:01:14 by ybekach           #+#    #+#              #
#    Updated: 2024/09/23 18:53:01 by ybekach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBMLX   = ~/MLX42

HEADERS = -I ./include -I $(LIBMLX)/include

LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC =  check_map.c get_map_file.c tools.c check_file.c  check_path.c show_map.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c move_player.c
OBJ = $(SRC:.c=.o)

MAIN = so_long.c \

MAIN_OBJ = $(MAIN:.c=.o)

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

$(NAME): $(OBJ) $(MAIN_OBJ)
	@echo "\n===============Compiling Libft=================\n"
	make -C libft
	@echo "\n===============LIBFT SUCCESS!!==================\n" 
	@echo "\n===============Compiling ft_printf==============\n" 
	make -C ft_printf
	@echo "\n===============FT_PRINTF SUCCESS!!================\n"
	@echo "\n===============Compiling LIBX================\n"
	make libmlx
	@echo "\n===============LIBX SUCCESS!!================\n"
	@echo "\n===============Compiling SO_LONG================\n" 
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) $(LIBFT) $(PRINTF) -o $(NAME) $(HEADERS) $(LIBS)
	@echo "\n===============SO_LONG SUCCES===================\n" 

all: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	@echo "\n==============Objects Cleaned=================\n" 



fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)
	@echo "\n================EXE Cleaned=====================\n" 

re:	fclean all

.PHONY: clean 


