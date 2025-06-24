/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:50:33 by abougrai          #+#    #+#             */
/*   Updated: 2024/02/01 17:12:50 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_number(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_long_atoi(av[i]) > MAX_INT || ft_strlen(av[i]) > 11)
			return (1);
		i++;
	}
	return (0);
}

void	init_mutex(t_general *general)
{
	pthread_mutex_init(&general->print, NULL);
	pthread_mutex_init(&general->mutex_stop, NULL);
	pthread_mutex_init(&general->mutex_time, NULL);
	pthread_mutex_init(&general->mutex_eat, NULL);
	pthread_mutex_init(&general->mutex_end, NULL);
	pthread_mutex_init(&general->mutex_death, NULL);
	pthread_mutex_init(&general->mutex_has_e, NULL);
}

void	init_general(t_general *general, int ac, char **av)
{
	general->forks = ft_long_atoi(av[1]);
	general->tt_die = ft_long_atoi(av[2]);
	general->tt_eat = ft_long_atoi(av[3]);
	general->tt_sleep = ft_long_atoi(av[4]);
	if (general->tt_sleep < general->tt_eat)
		general->tt_sleep = ft_long_atoi(av[4]) + (ft_long_atoi(av[3])
				- ft_long_atoi(av[4]) + 1);
	else
		general->tt_sleep = ft_long_atoi(av[4]) + 1;
	general->time_zero = 0;
	general->max_eat = -1;
	general->end = 0;
	general->even = 1;
	if (ac == 6)
		general->max_eat = ft_long_atoi(av[5]);
	if (general->forks % 2 == 1)
		general->even = 0;
	init_mutex(general);
}

void	init_main(t_general *general, int ac, char **av)
{
	if (ft_check_arg(av) || ft_check_number(av))
		exit_prog(NULL, ARG, 0);
	else if (!ft_long_atoi(av[1]))
		exit_prog(NULL, ATLEAST, 0);
	else if (ac == 6 && !ft_long_atoi(av[5]))
		exit_prog(NULL, SIM, 0);
	init_general(general, ac, av);
}
