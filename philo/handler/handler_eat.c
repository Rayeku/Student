/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:17:37 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 20:25:15 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_stop(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->forks)
	{
		pthread_mutex_lock(&general->mutex_stop);
		general->philo[i].stop = 1;
		pthread_mutex_unlock(&general->mutex_stop);
	}
}

void	set_end(t_general *general)
{
	pthread_mutex_lock(&general->mutex_end);
	general->end = 1;
	pthread_mutex_unlock(&general->mutex_end);
}

int	check_stop_or_dead(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->forks)
	{
		pthread_mutex_lock(&general->mutex_stop);
		if (general->philo[i].stop || general->philo[i].is_dead)
		{
			pthread_mutex_unlock(&general->mutex_stop);
			return (1);
		}
		pthread_mutex_unlock(&general->mutex_stop);
	}
	return (0);
}

int	ft_checker_eat(t_general *general, int philos)
{
	int	i;
	int	full;
	int	max;

	i = 0;
	full = 0;
	max = general->max_eat;
	while (i < philos)
	{
		pthread_mutex_lock(&general->mutex_has_e);
		if (general->philo[i].max_eat >= max)
			full++;
		pthread_mutex_unlock(&general->mutex_has_e);
		if (full == philos)
			return (1);
		i++;
	}
	return (0);
}

void	*handler_eat(void *arg)
{
	t_general	*general;
	int			i;

	general = arg;
	usleep(K);
	while (1)
	{
		i = -1;
		while (++i < general->forks)
		{
			pthread_mutex_lock(&general->mutex_end);
			if (general->end == 1)
			{
				pthread_mutex_unlock(&general->mutex_end);
				return (NULL);
			}
			pthread_mutex_unlock(&general->mutex_end);
			if (check_stop_or_dead(general))
				return (set_stop(general), NULL);
			if (ft_checker_eat(general, general->forks))
				return (set_end(general), set_stop(general), (NULL));
		}
		usleep(500);
	}
	return (NULL);
}
