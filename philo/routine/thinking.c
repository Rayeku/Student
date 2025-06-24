/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:40:39 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 17:14:32 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_thinking(t_philo *p)
{
	if (check_stop_or_death(p))
		return (1);
	pthread_mutex_lock(p->mutex_has_e);
	if (!p->has_e)
	{
		print_r(p, "think");
		pthread_mutex_unlock(p->mutex_has_e);
	}
	ft_usleep(1 / 10, p);
	return (0);
}
