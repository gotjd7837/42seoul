/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:01:56 by haekang           #+#    #+#             */
/*   Updated: 2023/09/04 21:17:50 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (-1);
	return ((mytime.tv_sec * 1000) + (mytime.tv_usec / 1000));
}

void	precise_sleep(uint64_t milliseconds)
{
	struct timeval	start;
	struct timeval	current;
	uint64_t		elapsed_time;

	elapsed_time = 0;
	gettimeofday(&start, NULL);
	while (elapsed_time < milliseconds)
	{
		gettimeofday(&current, NULL);
		elapsed_time = (current.tv_sec - start.tv_sec) * 1000 + \
						(current.tv_usec - start.tv_usec) / 1000;
	}
}
