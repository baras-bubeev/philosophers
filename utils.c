/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 05:20:31 by mpowder           #+#    #+#             */
/*   Updated: 2021/08/11 05:36:00 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_num(char *s)
{
	int	num;

	num = 0;
	while (*s)
	{
		num = num * 10 + ((*s) - '0');
		s++;
	}
	return (num);
}

void	ft_print(int id, char *s, t_parse *arg)
{
	pthread_mutex_lock(&arg->print);
	if (arg->die)
	{
		pthread_mutex_unlock(&arg->print);
		return ;
	}
	printf("%d %d %s", ft_gettime() - arg->tstart, id, s);
	pthread_mutex_unlock(&arg->print);
}

int	ft_gettime(void)
{
	struct timeval	tv;
	int				ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000000 + tv.tv_usec) / 1000;
	return (ms);
}

void	ft_sleep(int time)
{
	int	start;
	int	sleep_time;

	sleep_time = 0;
	start = ft_gettime();
	while (sleep_time < time)
	{
		usleep(10);
		sleep_time = ft_gettime() - start;
	}
}

void	ft_free(t_parse *arg, t_philosopher ***philo)
{
	int	i;

	i = -1;
	while (++i < arg->number)
		free(arg->fork[i]);
	free(arg->fork);
	i = -1;
	while (++i < arg->number)
		free((*philo)[i]);
	free(*philo);
}
