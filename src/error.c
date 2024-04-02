/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:30:17 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/02 13:15:52 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Clears allocated memory in the t_data structure.
 *
 * This function releases memory allocated for thread IDs, forks, and philosophers
 * in the t_data structure. It ensures that allocated memory is properly deallocated
 * to prevent memory leaks.
 *
 * @param data A pointer to the t_data structure to clear.
 */
static void	clear_data(t_data *data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

/**
 * @brief Exits the program and cleans up resources.
 *
 * This function performs cleanup operations before exiting the program. It destroys
 * mutexes associated with forks, philosophers, and output locks. Additionally, it
 * clears allocated memory in the t_data structure to prevent memory leaks.
 *
 * @param data A pointer to the t_data structure containing program data.
 */
static void	exit_and_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

/**
 * @brief Handles errors and exits the program gracefully.
 *
 * This function prints an error message to the standard output and calls exit_and_cleanup
 * to perform cleanup operations before exiting the program. It is used to handle
 * errors encountered during program execution.
 *
 * @param str A pointer to the error message string.
 * @param data A pointer to the t_data structure containing program data.
 *
 * @return An integer representing the error status.
 */
int	error(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	if (data)
		exit_and_cleanup(data);
	return (1);
}