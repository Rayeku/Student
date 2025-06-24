/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:40:39 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 14:28:42 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_sleeping(t_philo *p)
{
	pthread_mutex_lock(p->mutex_has_e);
	if (p->sleep)
	{
		p->sleep = 0;
		print_r(p, "sleep");
		pthread_mutex_unlock(p->mutex_has_e);
		ft_usleep(p->tt_sleep, p);
	}
	return (0);
}
