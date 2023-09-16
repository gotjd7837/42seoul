/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/16 19:19:35 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork\n");
	while (1)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		if (philo->data->philo_die == 1)
		{
			pthread_mutex_unlock(&philo->data->data_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->data_lock);
	}
	pthread_mutex_unlock(philo->l_fork);
	return ;
}

static void	*ph_trd(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	pthread_mutex_lock(&philo->ph_lock);
	philo->death_time = get_time() + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->ph_lock);
	if (philo->data->num_of_philo == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if ((philo->id + 1) % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		if (philo->data->philo_die == 1)
		{
			pthread_mutex_unlock(&philo->data->data_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->data_lock);
		start_eat(philo);
	}
	return (NULL);
}

int	start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->num_of_philo)
	{
		if (pthread_create(&(philo[i].tid), NULL, ph_trd, (void *)&(philo[i])))
			return (error("thread create error"));
		i++;
	}
	if (main_trd(data, philo))
		return (1);
	return (0);
}
