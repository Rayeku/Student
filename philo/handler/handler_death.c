/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:17:37 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 21:15:36 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_end(t_general *general)
{
	pthread_mutex_lock(&general->mutex_end);
	if (general->end == 1)
	{
		pthread_mutex_unlock(&general->mutex_end);
		return (1);
	}
	pthread_mutex_unlock(&general->mutex_end);
	return (0);
}

int	handle_death(t_general *general, int i)
{
	int	death;

	death = 0;
	pthread_mutex_lock(&general->mutex_stop);
	death = general->philo[i].is_dead;
	pthread_mutex_unlock(&general->mutex_stop);
	if (death)
		return (1);
	return (0);
}

void	philo_died(t_philo *p)
{
	pthread_mutex_lock(p->mutex_stop);
	p->is_dead = 1;
	pthread_mutex_unlock(p->mutex_stop);
	usleep(1 * K);
	pthread_mutex_lock(p->print);
	printf("\033[38;5;196m%ld %ld %s", init_time() - p->time_zero, p->index,
		DIED);
	pthread_mutex_unlock(p->print);
	return ;
}

void	*handler_death(void *arg)
{
	t_general	*general;
	int			i;

	general = arg;
	while (1)
	{
		i = -1;
		while (++i < general->forks)
		{
			pthread_mutex_lock(&general->mutex_time);
			if (((init_time() - general->philo[i].time_eat > general->tt_die))
				|| handle_death(general, i))
			{
				set_stop(general);
				philo_died(&general->philo[i]);
				pthread_mutex_unlock(&general->mutex_time);
				return (NULL);
			}
			pthread_mutex_unlock(&general->mutex_time);
		}
		if (ft_check_end(general))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
