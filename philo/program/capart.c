/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capart.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:26:30 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 14:50:25 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_even(t_philo *p)
{
	if (p->even)
	{
		if (p->index % 2 == 1)
			usleep(100);
	}
}

void	sleep_uneven(t_philo *p)
{
	if (!p->even)
	{
		if (p->index % 2 == 0)
			usleep(100);
	}
}

void	*philo_loop(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	sleep_even(p);
	sleep_uneven(p);
	while (!check_stop_or_death(p))
	{
		if (is_eating(p))
			return (NULL);
		if (is_sleeping(p))
			return (NULL);
		if (is_thinking(p))
			return (NULL);
	}
	return (NULL);
}

void	capart(t_general *general)
{
	int			i;
	pthread_t	death;
	pthread_t	eat;

	i = -1;
	while (++i < general->forks)
		pthread_create(&general->philo[i].thread, NULL, philo_loop,
			&general->philo[i]);
	pthread_create(&death, NULL, handler_death, general);
	if (general->max_eat != -1)
		pthread_create(&eat, NULL, handler_eat, general);
	pthread_join(death, NULL);
	if (general->max_eat != -1)
		pthread_join(eat, NULL);
	exit_prog(general, NULL, 1);
}
