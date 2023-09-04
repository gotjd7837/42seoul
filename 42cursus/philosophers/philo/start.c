/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/04 21:16:01 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_msg(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->r_fork);
	print_msg(philo, "has taken a fork\n");
	print_msg(philo, "is eating\n");
	philo->death_time = get_time() + philo->data->time_to_eat
		+ philo->data->time_to_die;
	philo->eat_cnt++;
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	print_msg(philo, "is sleeping\n");
	precise_sleep(philo->data->time_to_sleep);
	print_msg(philo, "is thinking\n");
}

static void	*master(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (philo->data->philo_die == 0)
	{
		if (get_time() >= philo->death_time)
		{
			print_msg(philo, "die\n");
			philo->data->philo_die = 1;
			break ;
		}
		if (philo->eat_cnt == philo->data->philo_must_eat)
		{
			philo->eat_cnt++;
			philo->data->finished_ph++;
		}
		if (philo->data->finished_ph == philo->data->num_of_philo)
			philo->data->philo_die = 1;
	}
	return (NULL);
}

static void	*ph_trd(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	philo->death_time = philo->data->time_to_die + get_time();
	if (pthread_create(&(philo->master_tid), NULL, master, (void *)philo))
		return ((void *)1);
	while (philo->data->philo_die == 0)
		start_eat(philo);
	if (pthread_join(philo->master_tid, NULL))
		return ((void *)1);
	return (NULL);
}

int	start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&(philo[i].tid), NULL, ph_trd, (void *)&(philo[i])))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (1);
		i++;
	}
	return (0);
}