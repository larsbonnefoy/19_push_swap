# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 09:29:55 by lbonnefo          #+#    #+#              #
#    Updated: 2023/01/16 15:20:25 by lbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES =	main.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		utils.c \
		utils2.c \
		min_sort.c \
		radix.c \
		normalize_stack.c \
		errors.c \
		parsing.c \
		parsing_utils.c \

SRCS= $(addprefix src/, $(FILES))

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

###LIB INCLUDES###

LIBFT_DIR = 19_libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = 19_ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAME): $(OBJ)
				make -C $(LIBFT_DIR)
				make -C $(PRINTF_DIR)
				cc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

.c.o:
		cc $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME) 

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		rm -rf $(OBJ)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(PRINTF_DIR)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
