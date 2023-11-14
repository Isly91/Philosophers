/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutexes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:56:20 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/10/12 15:37:31 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	death(t_generic *main_struct)
{
	pthread_mutex_lock(&main_struct->life);
	main_struct->dead_or_alive = 0;
	pthread_mutex_unlock(&main_struct->life);
}

int	mutex_lock_fork(t_philosopher *phi)
{
	int	right_fork;
	int	left_fork;

	right_fork = phi->philosopher_id % phi->generic_struct->num_philo;
	left_fork = (phi->philosopher_id + 1) % phi->generic_struct->num_philo;
	if (right_fork < left_fork)
	{
		pthread_mutex_lock(&phi->generic_struct->right_fork[left_fork]);
		print_message(phi, 1);
		pthread_mutex_lock(&phi->generic_struct->right_fork[right_fork]);
		print_message(phi, 1);
	}
	else
	{
		pthread_mutex_lock(&phi->generic_struct->right_fork[right_fork]);
		print_message(phi, 1);
		pthread_mutex_lock(&phi->generic_struct->right_fork[left_fork]);
		print_message(phi, 1);
	}
	return (0);
}

void	mutex_unlock_fork(t_philosopher *phi)
{
	int	right_fork;
	int	left_fork;

	right_fork = phi->philosopher_id % phi->generic_struct->num_philo;
	left_fork = (phi->philosopher_id + 1) % phi->generic_struct->num_philo;
	pthread_mutex_unlock(&phi->generic_struct->right_fork[right_fork]);
	pthread_mutex_unlock(&phi->generic_struct->right_fork[left_fork]);
}

int	mutex_init(t_generic *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		if (pthread_mutex_init(&main->right_fork[i], NULL) != 0)
			return (error_messages(6), 1);
		i++;
	}
	if (pthread_mutex_init(&main->life, NULL) != 0)
		return (error_messages(6), 1);
	if (pthread_mutex_init(&main->eating, NULL) != 0)
		return (error_messages(6), 1);
	return (0);
}

int	mutex_destroy(t_generic *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		if (pthread_mutex_destroy(&main->right_fork[i]) != 0)
			return (error_messages(7), 1);
		i++;
	}
	if (pthread_mutex_destroy(&main->life) != 0)
		return (error_messages(7), 1);
	if (pthread_mutex_destroy(&main->eating) != 0)
		return (error_messages(7), 1);
	return (0);
}
