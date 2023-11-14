/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 08:33:34 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/14 13:25:29 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define RED "\x1b[31;01m"
# define GREEN "\x1b[32;01m"
# define BLUE "\033[34;1m"
# define BOLD "\033[1m"
# define RESET "\x1b[0m"

typedef struct s_generic
{
	struct s_philosopher	*philo;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			life;
	pthread_mutex_t			eating;
	pthread_mutex_t			waiter;
	long					start_time;
	long					life_time;
	long					eat_time;
	long					sleep_time;
	int						num_philo;
	int						number_of_meals;
	int						dead_or_alive;
}	t_generic;

typedef struct s_philosopher
{
	pthread_t			philo;
	struct s_generic	*generic_struct;
	int					philosopher_id;
	int					eaten;
	long				last_eaten;
	long				sleeping;
	long				dying;
}	t_philosopher;

// parser
int			check_inputs(char **argv);
int			philo_atoi(char *s1);
void		error_messages(int which_error);
// main part
t_generic	*fill_in_struct(t_generic *main_struct, char **argv, int argc);
void		print_message(t_philosopher *philo, int what_to_print);
int			threads_and_routine(t_generic *main_struct);
int			mutex_lock_fork(t_philosopher *philo);
void		mutex_unlock_fork(t_philosopher *philo);
int			check_life(t_generic *main_struct);
void		*routine(void *philo_stru);
int			threads_and_routine(t_generic *main_struct);
int			create_philo(t_generic *main_struct);
int			philo_eating(t_philosopher *philo);
int			philo_sleeping(t_philosopher *philo);
int			philo_thinking(t_philosopher *philo);
void		death(t_generic *main_struct);
int			mutex_init(t_generic *main);
int			mutex_destroy(t_generic *main);
//timing
long		get_time(void);
// void		my_usleep(long parameter);
void 		my_usleep(long parameter);
int			monitoring(t_philosopher *philo, t_generic	*main_struct);
void		ft_free(t_generic *main);

#endif