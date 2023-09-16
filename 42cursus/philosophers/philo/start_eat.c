/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:59:35 by haekang           #+#    #+#             */
/*   Updated: 2023/09/16 19:01:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	put_fork(t_philo *philo)
{
	if ((philo->id + 1) % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

static void	get_fork(t_philo *philo)
{
	if ((philo->id + 1) % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_msg(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->l_fork);
		print_msg(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_msg(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->r_fork);
		print_msg(philo, "has taken a fork\n");
	}
}

void	start_eat(t_philo *philo)
{
	get_fork(philo);
	print_msg(philo, "is eating\n");
	pthread_mutex_lock(&philo->ph_lock);
	philo->death_time = get_time() + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->ph_lock);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->philo_must_eat)
	{
		pthread_mutex_lock(&philo->data->data_lock);
		philo->data->finished_ph++;
		pthread_mutex_unlock(&philo->data->data_lock);
	}
	ft_usleep(philo->data->time_to_eat);
	put_fork(philo);
	print_msg(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	print_msg(philo, "is thinking\n");
	usleep(700);
}
