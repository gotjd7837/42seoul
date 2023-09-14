/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/14 20:34:44 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_philo(t_data *data, t_philo *philo)
{
	int			i;
	long long	time;

	while (data->philo_die == 0)
	{
		pthread_mutex_lock(&data->data_lock);
		if (data->finished_ph == data->num_of_philo)
		{
			data->philo_die = 1;
			pthread_mutex_unlock(&data->data_lock);
			break ;
		}
		pthread_mutex_unlock(&data->data_lock);
		i = -1;
		while (++i < data->num_of_philo)
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
				break ;
			}
			pthread_mutex_unlock(&philo[i].ph_lock);
		}
	}
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
			return (1);
		i++;
	}
	check_philo(data, philo);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (1);
		i++;
	}
	return (0);
}
