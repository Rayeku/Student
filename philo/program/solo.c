/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:17:16 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 13:35:33 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_death_solo(t_philo *p)
{
	pthread_mutex_lock(p->mutex_death);
	if (get_time_now(p) - p->time_eat >= p->tt_die)
	{
		pthread_mutex_unlock(p->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(p->mutex_death);
	return (0);
}

void	print_r_solo(t_philo *p, char *r)
{
	if (!ft_strcmp("fork", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[0;34m%ld \033[0;32m%ld %s%s", get_time_now(p), p->index,
			HAS, FORK);
		pthread_mutex_unlock(p->print);
	}
	if (!ft_strcmp("dead", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[38;5;196m%ld %ld %s", get_time_now(p), p->index, DIED);
		pthread_mutex_unlock(p->print);
	}
}

void	*solo_loop(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	print_r_solo(p, "fork");
	while (!ft_death_solo(p))
		continue ;
	print_r_solo(p, "dead");
	return (NULL);
}

void	capart_solo(t_general *general)
{
	general->philo[0].time_zero = init_time();
	general->philo[0].time_eat = get_time_now(&general->philo[0]);
	pthread_create(&general->philo[0].thread, NULL, solo_loop,
		&general->philo[0]);
	exit_prog(general, NULL, 1);
}
