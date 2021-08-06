#include "philo.h"

void	parsing(int ac, char **av, t_parse *arg)
{
	arg->number = get_num(av[1]);
	arg->tdie = get_num(av[2]);
	arg->teat = get_num(av[3]);
	arg->tsleep = get_num(av[4]);
	if (ac == 5)
		arg->eat_num = -1;
	else
		arg->eat_num = get_num(av[5]);
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
	t_parse	arg;

	if (check_args(ac, av))
		return (1);
	parsing(ac, av, &arg);
	printf("%d\n%d\n%d\n%d\n%d\n", arg.number, arg.tdie, arg.teat, arg.tsleep, arg.eat_num);
	return (0);
}