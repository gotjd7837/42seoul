/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:28:26 by haekang           #+#    #+#             */
/*   Updated: 2023/09/16 18:09:11 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (1);
	memset(&data, 0, sizeof(t_data));
	if (set_data(&data, ac, av))
		return (1);
	if (set_philo(&data, &philo))
		return (1);
	if (start(&data, philo))
		return (1);
	return (0);
}
