/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:12:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/26 18:12:30 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

void	get_left_fork(t_philosopher	*philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork->forks);
    printf("Philosopher %ld picks up left fork\n", philosopher->philosopher_id);
}

void	get_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->right_fork->forks);
    printf("Philosopher %ld picks up right fork\n", philosopher->philosopher_id);
}

void	thinking(t_philosopher *philosopher)
{
	printf("Philosopher %ld is thinking...\n", philosopher->philosopher_id);
}

void	sleeping(t_philosopher *philosopher)
{
	usleep(philosopher->sleep_time);
	printf("Philosopher %ld is sleeping...\n", philosopher->philosopher_id);
}

void	release_left_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left_fork->forks);
	//printf("Philosopher %ld releases right fork\n", philosopher->philosopher_id);
}

void	release_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->right_fork->forks);
    //printf("Philosopher %ld releases right fork\n", philosopher->philosopher_id);
}

void	eating(t_philosopher *philosopher)
{
	//get_timing(philosopher);
	printf( GREEN "Philosopher %ld is eating...\n" RESET, philosopher->philosopher_id);
	usleep(philosopher->eat_time);
	release_left_fork(philosopher);
	release_right_fork(philosopher);
}
