/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:20:41 by haekang           #+#    #+#             */
/*   Updated: 2023/09/16 17:34:34 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *str)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->data_lock);
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->philo_die == 0)
	{
		time = get_time() - philo->data->start_time;
		printf("%llu %d %s", time, (philo->id + 1), str);
	}
	pthread_mutex_unlock(&philo->data->data_lock);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_die_msg(t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start_time;
	printf("%llu %d %s", time, (philo->id + 1), "died\n");
	pthread_mutex_unlock(&philo->data->print);
}
