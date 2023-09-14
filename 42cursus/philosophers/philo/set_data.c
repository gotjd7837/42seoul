/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:54:34 by haekang           #+#    #+#             */
/*   Updated: 2023/09/14 20:06:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	input_data_check(t_data *data, char *av[])
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 \
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0 \
		|| (av[5] != NULL && ft_atoi(av[5]) <= 0))
		return (1);
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = (u_int64_t)ft_atoi(av[2]);
	data->time_to_eat = (u_int64_t)ft_atoi(av[3]);
	data->time_to_sleep = (u_int64_t)ft_atoi(av[4]);
	return (0);
}

int	set_data(t_data *data, int ac, char *av[])
{
	int	i;

	i = 0;
	if (input_data_check(data, av))
		return (1);
	if (ac == 6)
		data->philo_must_eat = ft_atoi(av[5]);
	else if (ac == 5)
		data->philo_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!(data->forks))
		return (1);
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->forks[i++]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->data_lock, NULL))
		return (1);
	return (0);
}
