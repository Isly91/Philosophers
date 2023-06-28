/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 08:33:15 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/06/28 14:39:41 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int argc, char **argv)
{
	int i;
	t_philosopher *philosopher;

	i = 0;
	if ((argc < 5 || argc > 6) && check_inputs(argv) == 1)
		printf("Too few or too many arguments\n");
	else
	{
		if (check_inputs(argv) == 0)
		{
			printf("Error\n");
			return (0);
		}
		philosopher = (t_philosopher*) malloc(philo_atoi(argv[1]) * sizeof(t_philosopher));
		create_philo(philosopher, argv);
	}
	return (0);
}
//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]