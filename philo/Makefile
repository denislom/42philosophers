# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:44:23 by dlom              #+#    #+#              #
#    Updated: 2023/11/20 00:24:50 by dlom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo
SRCS =	philosophers.c \


OBJS = $(SRCS:.c=.o)

CC = cc -pthread
#CFLAGS = -Wall -Wextra -Werror -pthread -g

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