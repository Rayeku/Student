/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:40:39 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 20:55:26 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	time_eat(t_philo *p)
{
	pthread_mutex_lock(p->mutex_time);
	p->time_eat = init_time();
	pthread_mutex_unlock(p->mutex_time);
}

void	is_eatting(t_philo *p)
{
	pthread_mutex_lock(p->mutex_has_e);
	p->has_e = 1;
	p->max_eat++;
	p->sleep = 1;
	pthread_mutex_unlock(p->mutex_has_e);
}

int	even_index(t_philo *p)
{
	pthread_mutex_lock(p->r_fork);
	print_r(p, "fork");
	pthread_mutex_lock(&p->l_fork);
	print_r(p, "fork");
	if (check_stop_or_death(p))
	{
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(&p->l_fork);
		return (1);
	}
	time_eat(p);
	is_eatting(p);
	print_r(p, "eat");
	ft_usleep(p->tt_eat, p);
	pthread_mutex_lock(p->mutex_has_e);
	p->has_e = 0;
	pthread_mutex_unlock(p->mutex_has_e);
	pthread_mutex_unlock(&p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	return (0);
}

int	uneven_index(t_philo *p)
{
	pthread_mutex_lock(&p->l_fork);
	print_r(p, "fork");
	pthread_mutex_lock(p->r_fork);
	print_r(p, "fork");
	if (check_stop_or_death(p))
	{
		pthread_mutex_unlock(&p->l_fork);
		pthread_mutex_unlock(p->r_fork);
		return (1);
	}
	time_eat(p);
	is_eatting(p);
	print_r(p, "eat");
	ft_usleep(p->tt_eat, p);
	pthread_mutex_lock(p->mutex_has_e);
	p->has_e = 0;
	pthread_mutex_unlock(p->mutex_has_e);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(&p->l_fork);
	return (0);
}

int	is_eating(t_philo *p)
{
	if (check_stop_or_death(p))
		return (1);
	if (p->index % 2 == 1)
	{
		if (uneven_index(p))
			return (1);
	}
	else
	{
		if (even_index(p))
			return (1);
	}
	return (0);
}
