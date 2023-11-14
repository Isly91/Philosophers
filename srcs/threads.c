/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:48:07 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/14 13:14:27 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_life(t_generic *main_struct)
{
	pthread_mutex_lock(&main_struct->life);
	if (main_struct->dead_or_alive == 0)
	{
		pthread_mutex_unlock(&main_struct->life);
		return (0);
	}
	pthread_mutex_unlock(&main_struct->life);
	return (1);
}

void	*routine(void *philo_stru)
{
	t_philosopher	*philo;

	philo = philo_stru;
	if (philo->philosopher_id % 2 == 0)
	{
		print_message(philo, 4);
		usleep(1250);
	}
	while (check_life(philo->generic_struct))
	{
		// mutex_lock_fork(philo);
		philo_eating(philo);
		// mutex_unlock_fork(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}

int	join_philo(t_generic *main_struct)
{
	int		i;

	i = 0;
	while (i < main_struct->num_philo)
	{
		if (pthread_join(main_struct->philo[i].philo, NULL) != 0)
			return (error_messages(5), 1);
		i++;
	}
	return (0);
}

int	threads_and_routine(t_generic *main_struct)
{
	if (create_philo(main_struct))
		return (1);
	if (join_philo(main_struct))
		return (1);
	return (0);
}
