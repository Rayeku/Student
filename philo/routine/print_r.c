/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:25:12 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 18:41:16 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_r_bis(t_philo *p, char *r)
{
	if (check_stop_or_death(p))
		return (1);
	if (!ft_strcmp("think", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[0;34m%ld \033[0;32m%ld %s%s", get_time_now(p), p->index,
			IS, THINKING);
		pthread_mutex_unlock(p->print);
	}
	if (!ft_strcmp("sleep", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[0;34m%ld \033[0;32m%ld %s%s", get_time_now(p), p->index,
			IS, SLEEPING);
		pthread_mutex_unlock(p->print);
	}
	if (!ft_strcmp("dead", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[38;5;196m%ld %ld %s", get_time_now(p), p->index, DIED);
		pthread_mutex_unlock(p->print);
	}
	return (0);
}

int	print_r(t_philo *p, char *r)
{
	if (check_stop_or_death(p))
		return (1);
	if (!ft_strcmp("eat", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[0;34m%ld \033[0;32m%ld %s%s", get_time_now(p), p->index,
			IS, EATING);
		pthread_mutex_unlock(p->print);
	}
	if (!ft_strcmp("fork", r))
	{
		pthread_mutex_lock(p->print);
		printf("\033[0;34m%ld \033[0;32m%ld %s%s", get_time_now(p), p->index,
			HAS, FORK);
		pthread_mutex_unlock(p->print);
	}
	else
	{
		if (print_r_bis(p, r))
			return (1);
	}
	return (0);
}
