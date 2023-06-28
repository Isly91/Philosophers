/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_scheduling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 10:16:24 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/28 18:50:59 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void get_timing(t_philosopher *philosopher)
{
	struct timeval start_time;
	int time_result;
	//int i;

	//i = 0;
	time_result = gettimeofday(&start_time, NULL);
	//while (i < philo_atoi(argv[1]))
	//{
		philosopher->times.start_time_s = start_time.tv_sec;
		philosopher->times.start_time_ms = start_time.tv_usec;
		//i++;
	//}
	//printf("%ld\n", philosopher->times.start_time_s);
	//printf("%ld\n", philosopher->times.start_time_ms);
	//printf("%ld\n", philosopher->start_time_s);
	//if (time_result == 0)
	//	printf("Timer started\n");
	//else
	//	printf("Something went wrong\n");
}

void time_now(t_philosopher *philosopher)
{
	struct timeval current_time;
	int time_result;

	time_result = gettimeofday(&current_time, NULL);
    if (time_result == 0)
    {
		philosopher->current_time_s = current_time.tv_sec;
		philosopher->current_time_ms = current_time.tv_usec;
        philosopher->elapsed_time = (philosopher->current_time_s - philosopher->times.start_time_s) * 1000 + (philosopher->current_time_ms - philosopher->times.start_time_ms) / 1000;
		//printf("Elapsed time: %ld milliseconds\n", philosopher->elapsed_time);
	}
	else
	{
		printf("Something went wrong\n");
	}
}
//void	last_eating_time(t_philosopher *philosopher)
//{
//	struct timeval current_time;
//	int time_result;

//	time_result = gettimeofday(&current_time, NULL);
//	if (time_result == 0)
//    {
//		philosopher->current_time_s = current_time.tv_sec;
//		philosopher->current_time_ms = current_time.tv_usec;
//		//printf("%ld\n", philosopher->start_time_s);
//		//printf("%ld\n", philosopher->start_time_ms);
//		//printf("%ld\n", current_time_s);
//		//printf("%ld\n", current_time_ms);
		
//        philosopher->last_eating_time = (philosopher->current_time_s - philosopher->times.start_time_s) * 1000 + (philosopher->current_time_ms - philosopher->times.start_time_ms);
//		//printf("Elapsed time: %ld milliseconds\n", philosopher->elapsed_time);
//	}
//	else
//	{
//		printf("Something went wrong\n");
//	}
//}
