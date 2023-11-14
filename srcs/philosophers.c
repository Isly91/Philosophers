/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 08:33:15 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/11/14 16:21:26 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free_double_char(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i]);
	if (argv)
		free(argv);
}

void	ft_free(t_generic *main)
{
	if (main->philo)
		free(main->philo);
	if (main->right_fork)
		free (main->right_fork);
	if (main)
		free(main);
}

void	error_messages(int which_error)
{
	if (which_error == 1)
		printf("Allocation went wrong\n");
	else if (which_error == 2)
		printf("Too few or too many arguments\n");
	else if (which_error == 3)
		printf("Input error: each input must be bigger than 0\n");
	else if (which_error == 4)
		printf("Allocation went wrong\n");
	else if (which_error == 5)
		printf("Threads still running\n");
	else if (which_error == 6)
		printf("Mutexes have some conflicts\n");
	else if (which_error == 7)
		printf("Destroying mutexes was unsuccessful\n");
}

void	special_case(t_generic *main)
{
	if (!main)
		return ;
	printf("0 1 has taken a fork\n");
	my_usleep(main->life_time, main);
	printf(BOLD"%ld 1 died\n"RESET, main->life_time);
}

int	main(int argc, char **argv)
{
	t_generic	*main;

	main = NULL;
	if ((argc < 5 || argc > 6) || !argv)
		return (error_messages(2), 0);
	if (check_inputs(argv) == 0)
		return (error_messages(3), 0);
	main = fill_in_struct(main, argv, argc);
	if (!main)
		return (0);
	mutex_init(main);
	if (philo_atoi(argv[1]) == 1)
		special_case(main);
	else if (philo_atoi(argv[1]) > 1 && philo_atoi(argv[1]) <= 200)
		threads_and_routine(main);
	else
		printf("Please type num of philo between 1 and 200\n");
	mutex_destroy(main);
	ft_free(main);
	return (0);
}
