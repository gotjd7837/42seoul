/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:10 by haekang           #+#    #+#             */
/*   Updated: 2023/09/13 22:57:58 by haekang          ###   ########.fr       */
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
	if ((philo->id + 1) % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (philo->data->philo_die == 0)
		start_eat(philo);
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
