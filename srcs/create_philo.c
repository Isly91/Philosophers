/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:20:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/07/19 12:08:26 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philosopher_action(void *arg)
{
    t_philosopher	*philosopher;
	int i;
	
	philosopher = arg;
	i = 0;
	get_timing(philosopher);
	if (philosopher->philosopher_id % 2 == 0)
		my_usleep(philosopher->times.eat_time);
	while (1)
	{
		if (philosopher->times.must_eat || philosopher->dead_or_alive == 0)
		{
			if (i >= philosopher->times.must_eat)
				break ;
			i++;
		}
		get_left_fork(philosopher);
		get_right_fork(philosopher);
		time_now(philosopher);
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}
void	philo_0_attributes(t_philosopher	*philosopher, char **argv)
{
	philosopher[0].philosopher_id = 1;
	philosopher[0].dead_or_alive = 1;
	philosopher[0].times.life_time = philo_atoi(argv[2]);
	philosopher[0].times.eat_time = philo_atoi(argv[3]);
	philosopher[0].times.sleep_time = philo_atoi(argv[4]);
	philosopher[0].times.must_eat = philo_atoi(argv[5]);
	philosopher[0].right_fork = &philosopher[philo_atoi(argv[1]) - 1].left_fork;
}

void	create_forks(t_philosopher	*philosopher, char **argv)
{
	int i;

	i = 1;
	pthread_mutex_init(&philosopher[0].left_fork, NULL);
	pthread_mutex_init(&philosopher[0].times.print, NULL);
	while (i < philo_atoi(argv[1])) 
	{
		pthread_mutex_init(&philosopher[i].left_fork, NULL);
		pthread_mutex_init(&philosopher[i].times.print, NULL);
		philosopher[i].right_fork = &philosopher[i - 1].left_fork;
		philosopher[i].philosopher_id = i + 1;
		philosopher[i].dead_or_alive = 1;
		philosopher[i].times.life_time = philo_atoi(argv[2]);
		philosopher[i].times.eat_time = philo_atoi(argv[3]);
		philosopher[i].times.sleep_time = philo_atoi(argv[4]);
		philosopher[i].times.must_eat = philo_atoi(argv[5]);
		i++;
    }
	philo_0_attributes(philosopher, argv);
}

void create_philo(t_philosopher	*philosopher, char **argv)
{
	int i;

	i = 0;
	create_forks(philosopher, argv);
    while (i < philo_atoi(argv[1]))
	{
        pthread_create(&philosopher[i].philo, NULL, philosopher_action, &philosopher[i]);
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
		pthread_mutex_destroy(&philosopher[i].times.print);
		i++;
	}
}
