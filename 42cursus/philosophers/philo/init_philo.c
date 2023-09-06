/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:56:23 by haekang           #+#    #+#             */
/*   Updated: 2023/09/07 06:34:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philo);
	if (!*philo)
		return (1);
	while (i < data->num_of_philo)
	{
		(*philo)[i].data = data;
		(*philo)[i].id = i;
		(*philo)[i].die = 0;
		(*philo)[i].l_fork = &(data->forks[i]);
		(*philo)[i].r_fork = &(data->forks[(i + 1) % data->num_of_philo]);
		(*philo)[i].eat_cnt = 0;
		i++;
	}
	return (0);
}
