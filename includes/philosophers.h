/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 08:33:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/07/14 11:45:27 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>


# define RED "\x1b[31;01m"
# define GREEN "\x1b[32;01m"
# define BLUE "\033[34;1m"
# define BOLD "\033[1m"
# define RESET "\x1b[0m"

typedef struct timeval	t_timeval;

typedef struct s_generic
{
	long			start_time_s;
	long			start_time_ms;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	pthread_mutex_t	print;
} t_generic;

typedef struct s_philosopher
{
	pthread_t			philo;
	pthread_t			status;
	pthread_mutex_t		left_fork;
    pthread_mutex_t		*right_fork;
	t_generic			times;
	int					dead_or_alive;
	int					numero_di_volte;
	long				philosopher_id;
	long				current_time_s;
	long				current_time_ms;
	long				elapsed_time;
	long				last_eating_time;
} t_philosopher;

int		check_inputs(char **argv);
int		philo_atoi(char *s1);
void	create_forks(t_philosopher *philosopher, char **argv);
void	get_left_fork(t_philosopher	*philosopher);
void	get_right_fork(t_philosopher *philosopher);
void	eating(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	release_right_fork(t_philosopher *philosopher);
void	release_left_fork(t_philosopher *philosopher);
void	time_now(t_philosopher *philosopher);
void	eating_time(t_philosopher *philosopher);
void	*philo_is_death(void *philosopher);
void	create_philos(t_philosopher	*philosopher, char **argv);
void 	create_philo(t_philosopher	*philosopher, char **argv);
void	get_timing(t_philosopher *philosopher);
void	my_usleep(int parameter);
void	print_message(t_philosopher	*philosopher, char action);
void	ft_msleep(uint32_t milli_secs);

# endif