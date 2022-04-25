# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 16:20:40 by rlaforge          #+#    #+#              #
#    Updated: 2022/04/25 20:56:17 by rlaforge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

CLIB = ar -rcs

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CLIB) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
