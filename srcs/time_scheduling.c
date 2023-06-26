/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_scheduling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:16:24 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/26 18:38:15 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void get_timing(t_philosopher *philosopher)
{
	struct timeval start_time;
	int time_result;

	time_result = gettimeofday(&start_time, NULL);
	philosopher->start_time_s = start_time.tv_sec;
	philosopher->start_time_ms = start_time.tv_usec / 1000;
	if (time_result == 0)
		printf("Timer started\n");
	else
		printf("Something went wrong\n");
}

void time_now(t_philosopher *philosopher)
{
	struct timeval current_time;
	int time_result;
	long current_time_s;
	long current_time_ms;

	time_result = gettimeofday(&current_time, NULL);
    if (time_result == 0)
    {
		current_time_s = current_time.tv_sec;
		current_time_ms = current_time.tv_usec / 1000;
		printf("%ld\n", current_time_s);
		printf("%ld\n", philosopher->start_time_s);
		printf("%ld\n", current_time_ms);
		printf("%ld\n", philosopher->start_time_ms);
		
        philosopher->elapsed_time = (current_time_s - philosopher->start_time_s) * 1000 + (current_time_ms - philosopher->start_time_ms);
		//printf("Elapsed time: %ld milliseconds\n", philosopher->elapsed_time);
		//if (philosopher->elapsed_time > philosopher->life_time)
		//{
		//	printf(RED"Elapsed time: %d milliseconds\n"RESET, philosopher->life_time);
		//}
	}
	else
	{
		printf("Something went wrong\n");
	}
}
