/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:20:41 by haekang           #+#    #+#             */
/*   Updated: 2023/09/07 05:19:31 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *str)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->print);
	if (philo->data->philo_die == 0)
	{
		time = get_time() - philo->data->start_time;
		printf("%llu %d %s", time, (philo->id + 1), str);
	}
	pthread_mutex_unlock(&philo->data->print);
}

void	print_die_msg(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start_time;
	printf("%llu %d %s", time, (philo->id + 1), "died\n");
	pthread_mutex_unlock(&philo->data->print);
}

// typedef struct s_philo
// {
// 	t_data				*data;
// 	pthread_t			tid;
// 	pthread_t			master_tid;
// 	int					id;
// 	uint64_t			death_time;
// 	pthread_mutex_t		l_fork;
// 	pthread_mutex_t		r_fork;
// 	int					eat_cnt;
// }		t_philo;

// timestamp_in_ms X has taken a fork

// timestamp_in_ms X is eating

// timestamp_in_ms X is sleeping

// timestamp_in_ms X is thinking

// timestamp_in_ms X died