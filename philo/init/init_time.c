/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:31:09 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 12:38:08 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	init_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long int	get_time_now(t_philo *p)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - (p->time_zero));
}

void	ft_usleep(long int time, t_philo *p)
{
	long int	current_time;

	current_time = 0;
	current_time = get_time_now(p);
	while ((get_time_now(p) - current_time) < time)
	{
		if (check_stop_or_death(p))
			break ;
		if (time > 10000000)
			usleep(time / 100000);
		else
			usleep(time / 10);
	}
}
