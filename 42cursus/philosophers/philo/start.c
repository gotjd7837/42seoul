/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/05 21:17:09 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	loop_find_died(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (data->philo_die == 1)
		{
			while (i < data->num_of_philo)
			{
				if (philo[i].die == 1)
				{
					print_die_msg(&(philo[i]));
					break ;
				}
				i++;
			}
			break ;
		}
		else if (data->philo_die == 2)
			break ;
	}
	return ;
}

static void	start_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_msg(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->r_fork);
	print_msg(philo, "has taken a fork\n");
	print_msg(philo, "is eating\n");
	philo->death_time = get_time() + philo->data->time_to_die;
	philo->eat_cnt++;
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	print_msg(philo, "is sleeping\n");
	precise_sleep(philo->data->time_to_sleep);
	print_msg(philo, "is thinking\n");
}

static void	*maid_trd(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (1)
	{
		// pthread_mutex_lock(&philo->ph_lock);
		if (get_time() >= philo->death_time)
		{
			philo->die = 1;
			philo->data->philo_die = 1;
			break ;
		}
		if (philo->eat_cnt == philo->data->philo_must_eat)
		{
			philo->eat_cnt++;
			philo->data->finished_ph++;
		}
		if (philo->data->finished_ph == philo->data->num_of_philo)
		{
			philo->data->philo_die = 2;
			break ;
		}
	}
	return (NULL);
}

// static void	sleep_until_even_eat(t_data *arg)
// {
// 	struct timeval	get_time;
// 	struct timeval	timestamp;
// 	int				time_taken;

// 	gettimeofday(&get_time, NULL);
// 	while (1)
// 	{
// 		gettimeofday(&timestamp, NULL);
// 		time_taken = timestamp.tv_usec - get_time.tv_usec + \
// 			(timestamp.tv_sec - get_time.tv_sec) * 1000000;
// 		if (time_taken > arg->time_to_eat * 900)
// 			break ;
// 		usleep(arg->time_to_eat);
// 	}
// }

static void	*ph_trd(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	if ((philo->id + 1) % 2 == 0)
		precise_sleep(philo->data->time_to_eat);
	if (pthread_create(&(philo->maid_tid), NULL, maid_trd, (void *)philo))
		return ((void *)1);
	while (philo->data->philo_die == 0)
	{
		// pthread_mutex_lock(&philo->ph_lock);
		start_eat(philo);
		// pthread_mutex_unlock(&philo->ph_lock);
	}
	if (pthread_join(philo->maid_tid, NULL))
		return ((void *)1);
	return (NULL);
}

int	start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		philo[i].death_time = get_time() + philo->data->time_to_die;
		if (pthread_create(&(philo[i].tid), NULL, ph_trd, (void *)&(philo[i])))
			return (1);
		i++;
	}
	loop_find_died(data, philo);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (1);
		i++;
	}
	return (0);
}
