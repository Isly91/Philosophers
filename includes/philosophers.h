/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 08:33:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/26 18:19:46 by ibehluli      ########   odam.nl         */
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

typedef struct s_forks{
    pthread_mutex_t	forks;
} t_forks;

typedef struct s_philosopher{
	pthread_t	philo;
	t_forks		*left_fork;
    t_forks		*right_fork;
	long		start_time_s;
	long		start_time_ms;
	long		philosopher_id;
	long		left_fork_picked;
	long		right_fork_picked;
	long		fork_id;
	int			life_time;
	int			eat_time;
	int			sleep_time;
	int			must_eat;
	long		elapsed_time;
} t_philosopher;

int		check_inputs(char **argv);
int		philo_atoi(char *s1);
void	create_philo(t_philosopher* philosopher, char **argv);
void	eating();
void	get_timing();
void	get_left_fork(t_philosopher	*philosopher);
void	get_right_fork(t_philosopher *philosopher);
void	eating(t_philosopher *philosopher);
void	thinking(t_philosopher *philosopher);
void	sleeping(t_philosopher *philosopher);
void	time_now(t_philosopher *philosopher);

# endif