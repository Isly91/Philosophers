/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_scheduling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:16:24 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/07/19 11:30:50 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void get_timing(t_philosopher *philosopher)
{
	struct timeval start_time;

	if (gettimeofday(&start_time, NULL))
		printf("Something went wrong\n");
	philosopher->times.start_time_s = start_time.tv_sec;
	philosopher->times.start_time_ms = start_time.tv_usec;
}

void time_now(t_philosopher *philosopher)
{
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL))
		printf("Something went wrong\n");
	philosopher->current_time_s = current_time.tv_sec;
	philosopher->current_time_ms = current_time.tv_usec;
    philosopher->elapsed_time = (philosopher->current_time_s - philosopher->times.start_time_s) * 1000 + (philosopher->current_time_ms - philosopher->times.start_time_ms) / 1000;
}

void eating_time(t_philosopher *philosopher)
{
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL))
		printf("Something went wrong\n");
	philosopher->current_time_s = current_time.tv_sec;
	philosopher->current_time_ms = current_time.tv_usec;
    philosopher->last_eating_time = (philosopher->current_time_s - philosopher->times.start_time_s) * 1000 + (philosopher->current_time_ms - philosopher->times.start_time_ms) / 1000;
}

void	*philo_is_death(void *philosopher)
{
	struct timeval	curr_time;
	long			curr;
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = philosopher;
	printf("%d\n", philo->times.life_time);
	while (1)
	{
		gettimeofday(&curr_time, NULL);
		curr = (curr_time.tv_sec - philo->times.start_time_s) * 1000 + (curr_time.tv_usec - philo->times.start_time_ms) / 1000;
		if (curr - philo->last_eating_time > philo->times.life_time)
		{
			printf("Morto id: %ld al tempo %ld\n", philo->philosopher_id, curr);
			philo->dead_or_alive = 0;
			return (NULL);
		}
		my_usleep(20);
	}
}

void	my_usleep(int parameter)
{
	struct timeval start_time;
	long	tot_start;
	struct timeval curr_time;
	long	tot_curr;
	
	gettimeofday(&start_time, NULL);
	tot_start = (start_time.tv_sec) * 1000 + (start_time.tv_usec) / 1000;
	while (1)
	{
		usleep(100);
		gettimeofday(&curr_time, NULL);
		tot_curr = (curr_time.tv_sec) * 1000 + (curr_time.tv_usec) / 1000;
		if (tot_curr > tot_start + parameter)
			break ;
	}
}


