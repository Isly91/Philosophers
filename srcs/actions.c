/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:12:08 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/07/19 12:08:08 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

void	get_left_fork(t_philosopher	*philosopher)
{
	time_now(philosopher);
	pthread_mutex_lock(&philosopher->left_fork);
	print_message(philosopher, 'l');
}

void	get_right_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_message(philosopher, 'r');
}
void	sleeping(t_philosopher *philosopher)
{
	time_now(philosopher);
	print_message(philosopher, 's');
	my_usleep(philosopher->times.sleep_time);
}

void	thinking(t_philosopher *philosopher)
{
	print_message(philosopher, 't');
}

void	eating(t_philosopher *philosopher)
{
	time_now(philosopher);
	print_message(philosopher, 'e');
	my_usleep(philosopher->times.eat_time);
	pthread_mutex_unlock(&philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

void	print_message(t_philosopher	*philosopher, char action)
{
	if (action == 'l')
		printf("%ld %ld picks up left fork\n", philosopher->elapsed_time, philosopher->philosopher_id);
	else if (action == 'r')
		printf("%ld %ld picks up right fork\n", philosopher->elapsed_time, philosopher->philosopher_id);
	else if (action == 't')
		printf(BLUE "%ld %ld is thinking\n"RESET, philosopher->elapsed_time, philosopher->philosopher_id);
	else if (action == 's')
		printf(RED"%ld %ld is sleeping\n"RESET, philosopher->elapsed_time, philosopher->philosopher_id);
	else if (action == 'e')
		printf( GREEN "%ld %ld is eating\n" RESET, philosopher->elapsed_time, philosopher->philosopher_id);
}
