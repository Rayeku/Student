/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:40:29 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/27 12:45:50 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_general	general;

	if (ac == 5 || ac == 6)
	{
		init_main(&general, ac, av);
		init_thread(&general);
		if (general.forks == 1)
			capart_solo(&general);
		else
			capart(&general);
	}
	else
		exit_prog(NULL, ARG, 0);
}

/* void	printf_all(t_general *general)
{
	int	i;

	printf("forks : %ld\n", general->forks);
	printf("ttd : %ld\n", general->tt_die);
	printf("tte : %ld\n", general->tt_eat);
	printf("tt_sleep : %ld\n", general->tt_sleep);
	printf("max eat: %ld\n", general->max_eat);
	printf("end: %ld\n", general->end);
	printf("even: %ld\n", general->even);
	printf("\n");
	i = -1;
	while (++i < general->forks)
	{
		printf("index : %ld, ", general->philo[i].index);
		printf("die : %ld, ", general->philo[i].tt_die);
		printf("eat : %ld, ", general->philo[i].tt_eat);
		printf("sleep : %ld, ", general->philo[i].tt_sleep);
		printf("max eat :%ld", general->philo[i].max_eat);
		printf("even :%ld", general->philo[i].even);
		printf("stop : %ld, ", general->philo[i].stop);
		printf("has eat :%ld, ", general->philo[i].has_e);
		printf("is dead : %ld, ", general->philo[i].is_dead);
		printf("sleep :%ld", general->philo[i].sleep);
		printf("time eat :%ld", general->philo[i].time_eat);
		printf("time zero :%ld", general->philo[i].time_zero);
		printf("actual time %ld\n", get_time_now(&general->philo[i]));
	}
} */