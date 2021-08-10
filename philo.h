#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define INCORRECT_ARG_NUM "Error: Incorrect number of arguments.\n", 38
# define INVALID_ARGS "Error: Invalid arguments.\n", 26
# define MALLOC_ERROR "Error: Malloc: Memory was not allocated.\n", 41
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEPIN "is sleeping\n"
# define THINK "is thinking\n"
# define DIE "died\n"

typedef struct s_parse
{
    int				number;
	int				tdie;
	int				teat;
	int				tsleep;
	int				must_eat;
	int				ate_count;
	int				tstart;
	int				die;
	pthread_mutex_t	**fork;
	pthread_mutex_t	print;
}	t_parse;

typedef struct s_philosopher
{
	int			id;
	int			eat_count;
	int			last_eat;
	pthread_mutex_t			*fork1;
	pthread_mutex_t			*fork2;
	pthread_t	thread;
	t_parse		*arg;

}	t_philosopher;

int get_num(char *s);
int ft_gettime(void);
void    ft_sleep(int time);
void    thread_init(t_parse *arg, t_philosopher **philo);
void    ft_print(int id, char *s, t_parse *arg);
void	ft_free(t_parse *arg, t_philosopher ***philo);

#endif