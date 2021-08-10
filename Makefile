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