/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:12:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/28 18:49:03 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

void	get_left_fork(t_philosopher	*philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork);
    printf("%ld -- Philosopher %ld picks up left fork\n", philosopher->elapsed_time, philosopher->philosopher_id);
}

void	get_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
    printf("%ld -- Philosopher %ld picks up right fork\n", philosopher->elapsed_time, philosopher->philosopher_id);
}

void	thinking(t_philosopher *philosopher)
{
	printf(BLUE "%ld -- Philosopher %ld is thinking...\n"RESET, philosopher->elapsed_time, philosopher->philosopher_id);
}

void	sleeping(t_philosopher *philosopher)
{
	printf(RED"%ld -- Philosopher %ld is sleeping...\n"RESET, philosopher->elapsed_time, philosopher->philosopher_id);
	usleep(philosopher->times.sleep_time * 10000);
}

void	release_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork);
	printf("%ld -- Philosopher %ld rilascia sinistra\n", philosopher->elapsed_time, philosopher->philosopher_id);
}

void	release_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->right_fork);
	printf("%ld -- Philosopher %ld rilascia destra\n", philosopher->elapsed_time, philosopher->philosopher_id);
}

void	eating(t_philosopher *philosopher)
{
	//get_timing(philosopher);
	printf( GREEN "%ld -- Philosopher %ld is eating...\n" RESET, philosopher->elapsed_time, philosopher->philosopher_id);
	//get_timing(philosopher);
	usleep(philosopher->times.eat_time * 10000);
}

int	philo_is_death(t_philosopher *philosopher)
{
	if (philosopher->elapsed_time > philosopher->times.life_time)
	{
		//printf(RED"Elapsed time: %d milliseconds\n"RESET, philosopher->times.life_time);
		return (1);
	}
	return (0);
}
