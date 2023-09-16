/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_trd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:27:36 by haekang           #+#    #+#             */
/*   Updated: 2023/09/16 17:40:38 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	die_check(t_data *data, t_philo *philo)
{
	int			i;
	u_int64_t	time;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_lock(&philo[i].ph_lock);
		time = get_time();
		if (philo[i].death_time - time <= 0)
		{
			pthread_mutex_lock(&data->data_lock);
			data->philo_die = 1;
			pthread_mutex_unlock(&data->data_lock);
			print_die_msg(&philo[i]);
			pthread_mutex_unlock(&philo[i].ph_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo[i].ph_lock);
		i++;
	}
	return (0);
}

static int	finish_check(t_data *data)
{
	pthread_mutex_lock(&data->data_lock);
	if (data->finished_ph == data->num_of_philo)
	{
		data->philo_die = 1;
		pthread_mutex_unlock(&data->data_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->data_lock);
	return (0);
}

int	main_trd(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		if (data->philo_must_eat != -1)
		{
			if (finish_check(data))
				break ;
		}
		if (die_check(data, philo))
			break ;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (error("thread join error"));
		i++;
	}
	return (0);
}
