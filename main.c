#include "philo.h"

int	philo_init(t_philosopher ***philo, t_parse *arg)
{
	int	i;

	i = -1;
	(*philo) = malloc(sizeof(t_philosopher *) * arg->number);
	if (!(*philo))
		return (1);
	while (++i < arg->number)
	{
		(*philo)[i] = malloc(sizeof(t_philosopher));
		(*philo)[i]->id = i + 1;
		(*philo)[i]->eat_count = 0;
		(*philo)[i]->last_eat = 0;
		(*philo)[i]->arg = arg;
		if ((*philo)[i]->id % 2 == 0)
		{
			(*philo)[i]->fork1 = arg->fork[i];
			(*philo)[i]->fork2 = arg->fork[(i + 1) % arg->number];
		}
		else
		{
			(*philo)[i]->fork1 = arg->fork[(i + 1) % arg->number];
			(*philo)[i]->fork2 = arg->fork[i];
		}
	}
	return (0);
}

int	check_var(t_parse *arg)
{
	if (arg->number == 0 || arg->tdie == 0 || arg->tsleep == 0 ||
	arg->teat == 0 || arg->must_eat == 0)
	{
		write(2, INVALID_ARGS);
		return (1);
	}
	return (0);
}

int	var_init(int ac, char **av, t_parse *arg)
{
	int	i;

	arg->number = get_num(av[1]);
	arg->tdie = get_num(av[2]);
	arg->teat = get_num(av[3]);
	arg->tsleep = get_num(av[4]);
	arg->die = 0;
	if (ac == 5)
		arg->must_eat = -1;
	else
		arg->must_eat = get_num(av[5]);
	arg->ate_count = 0;
	arg->fork = malloc(sizeof(pthread_mutex_t *) * arg->number);
	if (!arg->fork)
		return (1);
	i = -1;
	while (++i < arg->number)
	{
		arg->fork[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(arg->fork[i], NULL);
	}
	pthread_mutex_init(&arg->print, NULL);
	return (0);
}

int check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
	{
		write(2, INCORRECT_ARG_NUM);
		return (1);
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(2, INVALID_ARGS);
				return (1);
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_parse			arg;
	t_philosopher	**philo;

	if (check_args(ac, av))
		return (1);
	if (var_init(ac, av, &arg) || philo_init(&philo, &arg))
	{
		write(2, MALLOC_ERROR);
		return (1);
	}
	if (check_var(&arg))
		return (1);
	thread_init(&arg, philo);
	ft_free(&arg, &philo);
	return (0);
}