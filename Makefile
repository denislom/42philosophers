# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:44:23 by dlom              #+#    #+#              #
#    Updated: 2023/11/18 20:57:24 by dlom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
SRCS =	big_sort_utils.c \
		big_sort.c \
		checks.c \
		free_functions.c \
		ft_atol.c \
		ft_list_functions.c \
		ft_list_functions2.c \
		operations_push.c \
		operations_reverse_rotate.c \
		operations_rotate.c \
		operations_swap.c \
		push_swap.c \
		small_sort.c

OBJS = $(SRCS:.c=.o)

CC = cc
#CFLAGS = -Wall -Wextra -Werror -g

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re