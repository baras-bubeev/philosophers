/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 05:20:36 by mpowder           #+#    #+#             */
/*   Updated: 2021/08/11 05:37:01 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *philo)
{
	t_philosopher	*ph;

	ph = (t_philosopher *)philo;
	while (!ph->arg->die)
	{
		pthread_mutex_lock(ph->fork1);
		ft_print(ph->id, FORK, ph->arg);
		pthread_mutex_lock(ph->fork2);
		ft_print(ph->id, FORK, ph->arg);
		ph->last_eat = ft_gettime() - ph->arg->tstart;
		ft_print(ph->id, EAT, ph->arg);
		ft_sleep(ph->arg->teat);
		ph->eat_count++;
		if (ph->arg->must_eat == ph->eat_count)
			ph->arg->ate_count++;
		pthread_mutex_unlock(ph->fork2);
		pthread_mutex_unlock(ph->fork1);
		ft_print(ph->id, SLEEPIN, ph->arg);
		ft_sleep(ph->arg->tsleep);
		ft_print(ph->id, THINK, ph->arg);
	}
	return (NULL);
}

void	monitoring(t_parse *arg, t_philosopher **philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < arg->number)
		{
			if (ft_gettime() - arg->tstart - philo[i]->last_eat > arg->tdie)
			{
				ft_print(philo[i]->id, DIE, arg);
				arg->die = 1;
				return ;
			}
			if (arg->ate_count == arg->number)
			{
				arg->die = 2;
				return ;
			}
		}
	}
}

void	thread_init(t_parse *arg, t_philosopher **philo)
{
	int				i;
	t_philosopher	*ph;

	i = -1;
	ph = (*philo);
	arg->tstart = ft_gettime();
	while (++i < arg->number)
	{
		pthread_create(&ph[i].thread, NULL, dinner, (void *)&ph[i]);
		usleep(50);
	}
	monitoring(arg, philo);
	i = -1;
	while (++i < arg->number)
	{
		if (arg->die == 1)
			pthread_detach(ph[i].thread);
		else
			pthread_join(ph[i].thread, NULL);
	}
}
