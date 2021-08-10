# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 05:20:27 by mpowder           #+#    #+#              #
#    Updated: 2021/08/11 05:20:30 by mpowder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= main.c philo.c utils.c

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re