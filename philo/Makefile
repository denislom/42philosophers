# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:44:23 by dlom              #+#    #+#              #
#    Updated: 2024/01/23 23:50:45 by dlom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo
SRCS =	philosophers.c \
		error_handling.c \
		parse.c \
		init.c \
		safe_func.c \
		setandget.c \
		dine.c \
		mon_and_synchro_utils.c \
		time_utils.c \
		output.c \
		death.c \
		clean_table.c \


OBJS = $(SRCS:.c=.o)

CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@	

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re