/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:16:59 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/25 12:37:34 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_thread(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->forks)
		pthread_mutex_destroy(&general->philo[i].l_fork);
}

void	destroy_mutex(t_general *general)
{
	pthread_mutex_destroy(&general->print);
	pthread_mutex_destroy(&general->mutex_eat);
	pthread_mutex_destroy(&general->mutex_stop);
	pthread_mutex_destroy(&general->mutex_time);
	pthread_mutex_destroy(&general->mutex_has_e);
	pthread_mutex_destroy(&general->mutex_death);
	pthread_mutex_destroy(&general->mutex_end);
}

void	wait_threads(t_general *general)
{
	int	i;

	i = -1;
	if (general->forks == 1)
	{
		pthread_join(general->philo[0].thread, NULL);
		return ;
	}
	while (++i < general->forks)
		pthread_join(general->philo[i].thread, NULL);
}

void	exit_prog(t_general *general, char *error, int mutex)
{
	if (general)
	{
		if (mutex && general->forks)
			wait_threads(general);
		if (mutex)
			destroy_mutex(general);
		if (general->forks)
			destroy_thread(general);
		if (general->philo)
			free(general->philo);
	}
	if (error)
		return (ft_putstr_fd(error, 2), exit(1));
	exit(0);
}
