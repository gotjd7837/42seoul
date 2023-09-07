/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/07 20:55:24 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_philo(t_data *data, t_philo *philo)
{
	int			i;
	long long	time;

	while (data->philo_die == 0)
	{
		if (data->finished_ph == data->num_of_philo)
		{
			data->philo_die = 1;
			break ;
		}
		i = 0;
		while (i < data->num_of_philo)
		{
			time = get_time();
			if (philo[i].death_time - time <= 0)
			{
				philo->data->philo_die = 1;
				print_die_msg(&philo[i]);
				break ;
			}
			i++;
		}
	}
	return ;
}

// static void	start_eat_r_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->r_fork);
// 	print_msg(philo, "has taken a fork\n");
// 	pthread_mutex_lock(philo->l_fork);
// 	print_msg(philo, "has taken a fork\n");
// 	print_msg(philo, "is eating\n");
// 	philo->death_time = get_time() + philo->data->time_to_die;
// 	philo->eat_cnt++;
// 	if (philo->eat_cnt == philo->data->philo_must_eat)
// 		philo->data->finished_ph++;
// 	ft_usleep(philo->data->time_to_eat);
// 	pthread_mutex_unlock(philo->r_fork);
// 	pthread_mutex_unlock(philo->l_fork);
// 	print_msg(philo, "is sleeping\n");
// 	ft_usleep(philo->data->time_to_sleep);
// 	print_msg(philo, "is thinking\n");
// 	// ft_usleep(3);
// }

static void	start_eat_l_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork\n");
	print_msg(philo, "is eating\n");
	philo->death_time = get_time() + philo->data->time_to_die;
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->philo_must_eat)
		philo->data->finished_ph++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_msg(philo, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
	print_msg(philo, "is thinking\n");
	// ft_usleep(3);
}

static void	*ph_trd(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	philo->death_time = get_time() + philo->data->time_to_die;
	if (philo->data->num_of_philo == 1)
	{
		print_msg(philo, "has taken a fork\n");
		while (philo->data->philo_die == 0)
			;
		return (NULL);
	}
	// if ((philo->id + 1) % 2 == 0)
	// {
	// 	while (philo->data->philo_die == 0)
	// 		start_eat_l_fork(philo);
	// }
	// else if ((philo->id + 1) % 2 == 1)
	// {
	// 	while (philo->data->philo_die == 0)
	// 		start_eat_r_fork(philo);
	// }
	if ((philo->id + 1) % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (philo->data->philo_die == 0)
		start_eat_l_fork(philo);
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
