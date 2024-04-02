/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:07:15 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/02 15:54:27 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Initializes the t_data structure with provided arguments.
 *
 * This function initializes the t_data structure with values parsed from command-line
 * arguments. It sets the number of philosophers, time constraints for death, eating,
 * and sleeping, as well as the number of meals if provided. Additionally, it initializes
 * two mutexes for thread-safe output and program lock.
 *
 * @param data A pointer to the t_data structure to initialize.
 * @param argv An array of strings containing command-line arguments.
 * @param argc The number of command-line arguments.
 *
 * @return An integer representing the success status. Returns 0 on success.
 */
static int	init_data(t_data *data, char *argv[], int argc)
{
	data->philo_num = ft_atoi(argv[1]);
	data->death_time = (uint64_t) ft_atoi(argv[2]);
	data->eat_time = (uint64_t) ft_atoi(argv[3]);
	data->sleep_time = (uint64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_nb = ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	data->is_dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

/**
 * @brief Allocates memory for arrays in the t_data structure.
 *
 * This function allocates memory for arrays in the t_data structure, including arrays
 * for thread IDs, mutexes representing forks, and t_philo structures representing
 * philosophers. It performs error handling and calls the error function in case of
 * allocation failure.
 *
 * @param data A pointer to the t_data structure.
 *
 * @return An integer representing the success status. Returns 0 on success.
 */
static int	allocate_data(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (error("ERROR WHILE ALLOCATING THREAD IDs", data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (error("ERROR WHILE ALLOCATING FORKS", data));
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (error("ERROR WHILE ALLOCATING PHILOSOPHERS", data));
	return (0);
}

/**
 * @brief Initializes mutexes representing forks for the dining philosophers.
 *
 * This function initializes mutexes representing forks for the dining philosophers.
 * It creates and initializes a mutex for each fork and assigns them to the appropriate
 * philosophers.
 *
 * @param data A pointer to the t_data structure.
 *
 * @return An integer representing the success status. Returns 0 on success.
 */
static int	init_forks(t_data *data)
{
	int	i;
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

/**
 * @brief Initializes t_philo structures with default values.
 *
 * This function initializes t_philo structures with default values and assigns them to
 * the corresponding philosophers. It sets the ID, time constraints, and other attributes
 * for each philosopher.
 *
 * @param data A pointer to the t_data structure.
 */
static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

/**
 * @brief Initializes the simulation environment.
 *
 * This function initializes the simulation environment by calling initialization
 * functions for data, memory allocation, forks, and philosophers. It ensures that all
 * components required for the simulation are properly initialized.
 *
 * @param data A pointer to the t_data structure.
 * @param argv An array of strings containing command-line arguments.
 * @param argc The number of command-line arguments.
 *
 * @return An integer representing the success status. Returns 0 on success.
 */
int	init(t_data *data, char *argv[], int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (allocate_data(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}