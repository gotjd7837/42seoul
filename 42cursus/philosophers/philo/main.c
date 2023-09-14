/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:28:26 by haekang           #+#    #+#             */
/*   Updated: 2023/09/14 21:20:46 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leak()
{
	system("leaks --list -- philo");
}

int	free_data(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->data_lock);
	free(data->forks);
	if ()
	return (1);
}


int	main(int ac, char *av[])
{
	atexit(leak);
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (1);
	memset(&data, 0, sizeof(t_data));
	if (set_data(&data, ac, av))
		return (1);
	if (init_philo(&data, &philo))
		return (1);
	if (start(&data, philo))
		return (1);
	// free_ph(&data, philo);
	return (0);
}


//-g -fsanitize=thread - 데이터 레이스 검사 플래그