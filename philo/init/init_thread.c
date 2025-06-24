/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:15:44 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 16:34:29 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_mutexes_philo(t_general *general, int i)
{
	general->philo[i].print = &general->print;
	general->philo[i].mutex_time = &general->mutex_time;
	general->philo[i].mutex_stop = &general->mutex_stop;
	general->philo[i].mutex_eat = &general->mutex_eat;
	general->philo[i].mutex_death = &general->mutex_death;
	general->philo[i].mutex_has_e = &general->mutex_has_e;
}

void	init_philo_bis(t_general *general, int i)
{
	general->philo[i].thread = 0;
	general->philo[i].index = i + 1;
	general->philo[i].tt_die = general->tt_die;
	general->philo[i].tt_eat = general->tt_eat;
	general->philo[i].tt_sleep = general->tt_sleep;
	general->philo[i].forks = general->forks;
	general->philo[i].time_eat = general->time_zero;
	general->philo[i].time_zero = general->time_zero;
}

void	init_philo(t_general *general)
{
	int	i;

	i = -1;
	general->time_zero = init_time();
	while (++i < general->forks)
	{
		init_philo_bis(general, i);
		general->philo[i].max_eat = 0;
		general->philo[i].even = general->even;
		general->philo[i].stop = 0;
		general->philo[i].has_e = 0;
		general->philo[i].is_dead = 0;
		general->philo[i].sleep = 0;
		general->philo[i].r_fork = NULL;
		pthread_mutex_init(&general->philo[i].l_fork, NULL);
		get_mutexes_philo(general, i);
		if (i == general->forks - 1)
			general->philo[i].r_fork = &general->philo[0].l_fork;
		else
			general->philo[i].r_fork = &general->philo[i + 1].l_fork;
	}
}

void	init_thread(t_general *general)
{
	general->philo = malloc(sizeof(t_philo) * general->forks);
	if (!general->philo)
		exit_prog(NULL, MALLOC, 0);
	init_philo(general);
}
