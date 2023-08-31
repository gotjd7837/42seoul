/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:28:26 by haekang           #+#    #+#             */
/*   Updated: 2023/08/31 11:13:17 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_data
{
	int				philo_num;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				minimum_eat_num;
	int				finished_ph;
	int				die;
	pthread_mutex_t	*forks;
}		t_data;

typedef struct s_philo
{
	t_data				*data;
	pthread_t			tid;
	pthread_t			master_tid;
	int					id;
	uint64_t			death_time;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		r_fork;
	int					eat_cnt;
	// u_int64_t	last_eat
}		t_philo;

void	start_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("포크 집음\n");
	pthread_mutex_lock(philo->r_fork);
	printf("포크 집음\n");
	philo->death_time = philo->data->time_to_die + get_time();
	printf("이 철학자가 식사중\n");
	philo->eat_cnt++;
	//주어진 시간만큼 식사한다
	pthread_mutex_unlock(philo->l_fork);
	printf("포크 내려놓음\n");
	pthread_mutex_unlock(philo->r_fork);
	printf("포크 내려놓음\n");
	//주어진 시간만큼 쳐잔다
}

void	*master(void *someone_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)someone_pointer;
	while (philo->data->die == 0)
	{
		if (get_time() >= philo->death_time)
		{
			printf("이 철학자 죽음\n");
			philo->data->die = 1;
		}
		if (philo->eat_cnt == philo->data->minimum_eat_num)
		{
			// philo->eat_cnt++;
			philo->data->finished_ph++;
			//다먹음 ㅇㅇ
		}
		if (philo->data->finished_ph == philo->data->philo_num)
			philo->data->die = 1;//만약 모든 철학자가 다먹었으면 다 죽여서 시뮬레이션 종료
	}
}

void	*ph_sit(void *someone_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)someone_pointer;
	philo->death_time = philo->data->time_to_die + get_time();
	if (pthread_create(&(philo->master_tid), NULL, master, (void *)philo))
		return ;
	while (philo->data->die == 0)
		start_eat(philo);
	if (pthread_join(philo->master_tid, NULL))
		return ;
}

int	start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&(philo[i].tid), NULL, ph_sit, (void *)&philo[i]))
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		return (1);
	while (i < data->philo_num)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].l_fork = data->forks[i];
		philo[i].r_fork = data->forks[(i + 1) % data->philo_num];
		philo[i].eat_cnt = 0;
		i++;
	}
	return (0);
}

int	set_data(t_data *data, int ac, char *av[])
{
	int	i;

	i = 0;
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = (uint64_t)ft_atoi(av[2]);
	data->time_to_eat = (uint64_t)ft_atoi(av[3]);
	data->time_to_sleep = (uint64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->minimum_eat_num = ft_atoi(av[5]);
	else if (ac == 5)
		data->minimum_eat_num = -1;
	data->forks = malloc(sizeof(pthread_mutex_t *) * data->philo_num);
	if (!(data->forks))
		return (1);
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&(data->forks)[i++], NULL))
			return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (1);
	memset(&data, 0, sizeof(t_data));
	if (set_data(&data, ac, av))
		return (1);
	if (init_philo(&data, philo))
		return (1);
	if (start(&data, philo))
		return (1);
	return (0);
}
