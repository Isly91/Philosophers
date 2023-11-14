/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:12:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/14 15:59:49 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eating(t_philosopher *philo)
{
	mutex_lock_fork(philo);
	pthread_mutex_lock(&philo->generic_struct->eating);
	philo->last_eaten = get_time();
	philo->eaten++;
	print_message(philo, 2);
	pthread_mutex_unlock(&philo->generic_struct->eating);
	my_usleep(philo->generic_struct->eat_time, philo->generic_struct);
	mutex_unlock_fork(philo);
	return (0);
}

int	philo_sleeping(t_philosopher *philo)
{
	if (!check_life(philo->generic_struct))
		return (1);
	print_message(philo, 3);
	my_usleep(philo->generic_struct->sleep_time, philo->generic_struct);
	return (0);
}

int	philo_thinking(t_philosopher *philo)
{
	if (!check_life(philo->generic_struct))
		return (1);
	print_message(philo, 4);
	usleep(500);
	return (0);
}

void	print_message(t_philosopher *philo, int what_to_print)
{
	pthread_mutex_lock(&philo->generic_struct->life);
	if (what_to_print == 0 && philo->generic_struct->dead_or_alive == 1)
		printf ("%ld %d died\n", get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	else if (what_to_print == 1 && philo->generic_struct->dead_or_alive == 1)
		printf ("%ld %d has taken a fork\n", get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	else if (what_to_print == 2 && philo->generic_struct->dead_or_alive == 1)
		printf (GREEN"%ld %d is eating\n"RESET, get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	else if (what_to_print == 3 && philo->generic_struct->dead_or_alive == 1)
		printf (RED"%ld %d is sleeping\n"RESET, get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	else if (what_to_print == 4 && philo->generic_struct->dead_or_alive == 1)
		printf ("%ld %d is thinking\n"RESET, get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	else if (what_to_print == 5 && philo->generic_struct->dead_or_alive == 0)
		printf (BOLD"%ld %d died\n"RESET, get_time()
			- philo->generic_struct->start_time, philo->philosopher_id);
	pthread_mutex_unlock(&philo->generic_struct->life);
}
