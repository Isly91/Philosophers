/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:20:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/26 18:31:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philosopher_action(void *arg)
{
    t_philosopher	*philosopher;
	int i;
	
	philosopher = arg;
	i = 0;
	if (philosopher->left_fork == NULL)
	{
		usleep(philosopher->life_time);
		get_right_fork(philosopher);
		time_now(philosopher);
		printf(RED"%ld Philosopher %ld died.\n" RESET, philosopher->elapsed_time, philosopher->philosopher_id);
		return (NULL);
	}
	while (i < philosopher->must_eat)
	{
		get_right_fork(philosopher);
		get_left_fork(philosopher);
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
		//timer(philosopher);
		i++;
	}
	return (NULL);
}

void	create_forks()
{
	
}

void	add_time_frames(t_philosopher	*philosopher, char **argv)
{
		philosopher->life_time = philo_atoi(argv[2]);
		philosopher->eat_time = philo_atoi(argv[3]);
		philosopher->sleep_time = philo_atoi(argv[4]);
		philosopher->must_eat = philo_atoi(argv[5]);
}

void	create_philos(t_philosopher	*philosopher, t_forks	*forks, char **argv)
{
	int i;

	i = 0;
	while (i < philo_atoi(argv[1])) 
	{
		if (philo_atoi(argv[1]) == 1)
		{
			philosopher[i].philosopher_id = i + 1;
			philosopher[i].right_fork= &forks[i + 1];
			philosopher[i].left_fork = NULL;
		}
		else if (i == philo_atoi(argv[1]) - 1)
		{
            philosopher[i].philosopher_id = i + 1;
            philosopher[i].left_fork = philosopher[0].right_fork;
            philosopher[i].right_fork= &forks[i + 1];
		}
		else
		{
			philosopher[i].left_fork = &forks[i + 1];
			philosopher[i].right_fork = &forks[i];
			philosopher[i].philosopher_id = i + 1;
        }
		add_time_frames(&philosopher[i], argv);
		i++;
    }
}

void create_philo(t_philosopher	*philosopher, char **argv)
{
    t_forks	*forks;
	int i;

	i = 0;
	forks = (t_forks *) malloc(philo_atoi(argv[1]) * sizeof(t_forks));
	while (i < philo_atoi(argv[1])) 
	{
		pthread_mutex_init(&forks[i].forks, NULL);
		i++;
    }
	i = 0;
	create_philos(philosopher, forks, argv);
    while (i < philo_atoi(argv[1])) 
	{
        pthread_create(&philosopher[i].philo, NULL, philosopher_action, &philosopher[i]);
		get_timing(philosopher[i]);
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
		pthread_mutex_destroy(&forks[i].forks);
		i++;
	}
	free(forks);
}
