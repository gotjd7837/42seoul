/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:54:34 by haekang           #+#    #+#             */
/*   Updated: 2023/09/04 21:22:46 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_data(t_data *data, int ac, char *av[])
{
	int	i;

	i = 0;
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = (uint64_t)ft_atoi(av[2]);
	data->time_to_eat = (uint64_t)ft_atoi(av[3]);
	data->time_to_sleep = (uint64_t)ft_atoi(av[4]);
	data->start_time = get_time();
	if (ac == 6)
		data->philo_must_eat = ft_atoi(av[5]);
	else if (ac == 5)
		data->philo_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!(data->forks))
		return (1);
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->forks)[i++], NULL))
			return (1);
	}
	pthread_mutex_init(&data->print, NULL);
	return (0);
}
