/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:49:19 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/28 09:13:33 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_checker_death(t_philo *p)
{
	pthread_mutex_lock(p->mutex_death);
	if (init_time() - p->time_eat >= p->tt_die)
	{
		pthread_mutex_unlock(p->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(p->mutex_death);
	return (0);
}

int	check_stop_or_death(t_philo *p)
{
	if (ft_checker_death(p))
	{
		pthread_mutex_lock(p->mutex_stop);
		p->is_dead = 1;
		pthread_mutex_unlock(p->mutex_stop);
		return (1);
	}
	pthread_mutex_lock(p->mutex_stop);
	if (p->stop)
	{
		pthread_mutex_unlock(p->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(p->mutex_stop);
	return (0);
}
