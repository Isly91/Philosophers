/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_scheduling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:16:24 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/14 16:21:12 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_time(void)
{
	struct timeval	start_time;
	long			curr;

	gettimeofday(&start_time, NULL);
	curr = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	return (curr);
}

void	my_usleep(long parameter, t_generic *dead_break)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < parameter)
	{
		pthread_mutex_lock(&dead_break->eating);
		pthread_mutex_lock(&dead_break->life);
		if (dead_break->dead_or_alive == 0
			|| dead_break->philo->eaten == dead_break->number_of_meals)
		{
			pthread_mutex_unlock(&dead_break->life);
			pthread_mutex_unlock(&dead_break->eating);
			break ;
		}
		pthread_mutex_unlock(&dead_break->life);
		pthread_mutex_unlock(&dead_break->eating);
		usleep(200);
	}
}

int	monitoring(t_philosopher *philo, t_generic	*main_struct)
{
	int	i;

	i = 0;
	while (i < philo->generic_struct->num_philo)
	{
		pthread_mutex_lock(&philo->generic_struct->eating);
		if (get_time() - philo[i].last_eaten >= main_struct->life_time)
		{
			pthread_mutex_unlock(&philo->generic_struct->eating);
			death(main_struct);
			print_message(&philo[i], 5);
			return (1);
		}
		pthread_mutex_unlock(&philo->generic_struct->eating);
		i++;
	}
	return (0);
}
