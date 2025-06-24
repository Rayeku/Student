/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:45:07 by abougrai          #+#    #+#             */
/*   Updated: 2024/01/28 16:59:37 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RESET "\033[0m"
# define BLEU "\033[94m"
# define JAUNE "\033[33m"
# define VIOLET "\033[95m"
# define ROUGE "\033[38;5;196m"
# define VIOLET_CLAIR "\033[95m"
# define ORANGE "\033[38;5;208m"
# define CYAN_LIGHT "\033[0;96m"
# define BLEU_FONCE "\033[38;5;33m"
# define BLEU_MARINE "\033[38;5;24m"

# define BROWN "\033[38;2;139;69;19m"

# define IS "\033[0mis \033[0m"
# define HAS "\033[0mhas taken a \033[0m"
# define DIED "died\n"
# define THINKING "\033[38;5;33mthinking\n\033[0m"
# define SLEEPING "\033[0;96msleeping\n\033[0m"
# define EATING "\033[38;5;208meating\n\033[0m"
# define FORK "\033[38;2;139;69;19mfork\n\033[0m"
# define MALLOC "\033[38;5;196mError malloc\n\033[0m"
# define ARG "\033[38;2;139;69;19mInvalid argument\n\033[0m"
# define SIM "\033[38;2;139;69;19mNo simulation required\n\033[0m"
# define ATLEAST "\033[38;5;196mSimulation needs at least 1 philo\n\033[0m"

# define MAX_INT 2147483647
# define K 1000

typedef struct s_philo
{
	pthread_t		thread;
	long int		index;
	long int		tt_die;
	long int		tt_eat;
	long int		tt_sleep;
	long int		max_eat;
	long int		even;
	long int		stop;
	long int		has_e;
	long int		is_dead;
	long int		sleep;
	long int		time_eat;
	long int		forks;
	long int		time_zero;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*mutex_time;
	pthread_mutex_t	*mutex_stop;
	pthread_mutex_t	*mutex_eat;
	pthread_mutex_t	*mutex_end;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*mutex_has_e;

}					t_philo;

typedef struct s_general
{
	long int		forks;
	long int		tt_die;
	long int		tt_eat;
	long int		tt_sleep;
	long int		time_zero;
	long int		max_eat;
	long int		end;
	long int		even;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_end;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_has_e;
	t_philo			*philo;

}					t_general;

// init
void				init_main(t_general *general, int ac, char **av);
void				init_thread(t_general *general);

// init.c
long int			init_time(void);
long int			get_time_now(t_philo *p);
void				ft_usleep(long int time, t_philo *p);

// program
void				capart(t_general *general);
void				capart_solo(t_general *general);
int					check_stop_or_death(t_philo *p);
void				exit_prog(t_general *general, char *error, int mutex);

// routine
int					print_r(t_philo *p, char *r);
int					is_eating(t_philo *p);
int					is_sleeping(t_philo *p);
int					is_thinking(t_philo *p);

// handler
void				*handler_eat(void *arg);
void				*handler_death(void *arg);
void				set_stop(t_general *general);

// tools1.c
long int			ft_long_atoi(const char *nptr);
int					ft_isdigit(int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
void				ft_putstr_fd(char *s, int fd);

//	garbage
void				printf_all(t_general *general);

#endif