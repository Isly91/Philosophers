/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:20:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/28 18:51:10 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philosopher_action(void *arg)
{
    t_philosopher	*philosopher;
	int i;
	
	philosopher = arg;
	i = 0;
	if (philosopher->philosopher_id % 2 == 0)
		usleep(10000);
	//get_timing(philosopher);
	while (i < philosopher->numero_di_volte)
	{
		if (philosopher->times.must_eat)
		{
			if (i >= philosopher->times.must_eat)
				break ;
			i++;
		}
		time_now(philosopher);
		get_left_fork(philosopher);
		time_now(philosopher);
		get_right_fork(philosopher);
		time_now(philosopher);
		eating(philosopher);
		time_now(philosopher);
		release_left_fork(philosopher);
		time_now(philosopher);
		release_right_fork(philosopher);
		time_now(philosopher);
		sleeping(philosopher);
		time_now(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}

void	add_time_frames(t_philosopher	*philosopher, char **argv)
{
		philosopher->times.life_time = philo_atoi(argv[2]);
		philosopher->times.eat_time = philo_atoi(argv[3]);
		philosopher->times.sleep_time = philo_atoi(argv[4]);
		philosopher->times.must_eat = philo_atoi(argv[5]);
}

void	create_forks(t_philosopher	*philosopher, char **argv)
{
	int i;

	i = 1;
	pthread_mutex_init(&philosopher[0].left_fork, NULL);
	while (i < philo_atoi(argv[1])) 
	{
		philosopher[i].right_fork = &philosopher[i - 1].left_fork;
		i++;
    }
	philosopher[0].right_fork = &philosopher[i - 1].left_fork;
}

void	create_philos(t_philosopher	*philosopher, char **argv)
{
	int i;

	i = 0;
	while (i < philo_atoi(argv[1]))
	{
		philosopher[i].philosopher_id = i + 1;
		philosopher[i].numero_di_volte = philo_atoi(argv[5]);
		philosopher[i].times.life_time = philo_atoi(argv[2]);
		philosopher[i].times.eat_time = philo_atoi(argv[3]);
		philosopher[i].times.sleep_time = philo_atoi(argv[4]);
		philosopher[i].times.must_eat = philo_atoi(argv[5]);
		//add_time_frames(&philosopher[i], argv);
		i++;
	}
}

void create_philo(t_philosopher	*philosopher, char **argv)
{
	int i;

	i = 0;
	create_forks(philosopher, argv);
	create_philos(philosopher, argv);
    while (i < philo_atoi(argv[1]))
	{
        pthread_create(&philosopher[i].philo, NULL, philosopher_action, &philosopher[i]);
		get_timing(&philosopher[i]);
		i++;
    }
	i = 0;
    while (i < philo_atoi(argv[1]))
	{
		pthread_join(philosopher[i].philo, NULL);
		i++;
    }
	i = 0;
    while (i < philo_atoi(argv[1]))
	{
		pthread_mutex_destroy(&philosopher[i].left_fork);
		i++;
	}
}
