/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:59:41 by haekang           #+#    #+#             */
/*   Updated: 2023/09/20 16:56:42 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>

typedef struct s_data
{
	int				num_of_philo;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		start_time;
	int				philo_must_eat;
	int				finished_ph;
	int				philo_die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	data_lock;
}		t_data;

typedef struct s_philo
{
	t_data				*data;
	pthread_t			tid;
	int					id;
	int					die;
	u_int64_t			death_time;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		ph_lock;
	int					eat_cnt;
}		t_philo;

int			ft_atoi(const char *str);
u_int64_t	get_time(void);

int			set_data(t_data *data, int ac, char *av[]);

int			set_philo(t_data *data, t_philo **philo);

int			start(t_data *data, t_philo *philo);

void		start_eat(t_philo *philo);

void		print_msg(t_philo *philo, char *str);
void		print_die_msg(t_philo *philo);

void		ft_usleep(u_int64_t time_ms, t_philo *philo);

int			main_trd(t_data *data, t_philo *philo);
int			error(char *str);

#endif