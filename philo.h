#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define INCORRECT_ARG_NUM "Error: Incorrect number of arguments.\n", 38
# define INVALID_ARGS "Error: Invalid arguments.\n", 26

typedef struct s_parse
{
    int	number;
	int	tdie;
	int	teat;
	int	tsleep;
	int	eat_num;
}	t_parse;

int get_num(char *s);

#endif