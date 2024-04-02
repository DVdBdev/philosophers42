/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:40:20 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/02 15:38:38 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Supervisor function for a philosopher thread.
 *
 * This function serves as the supervisor for a philosopher thread. It continuously
 * monitors the state of the philosopher and reacts accordingly. If the philosopher
 * hasn't eaten for too long and is not currently eating, it sends a message that
 * the philosopher has died. Additionally, it checks if the philosopher has finished
 * all the meals and updates the counter accordingly.
 *
 * @param philo_ptr A pointer to the philosopher structure.
 *
 * @return NULL.
 */
void	*supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->eat_count == philo->data->meals_nb)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}


/**
 * @brief Monitor function for monitoring the dining process.
 *
 * This function monitors the dining process by checking if all philosophers have
 * finished their meals. Once all philosophers have finished, it sets the 'is_dead'
 * flag to 1, indicating the end of the simulation.
 *
 * @param data_ptr A pointer to the data structure containing information about the
 *                dining process.
 *
 * @return NULL.
 */
void	*monitor(void *data_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) data_ptr;
	pthread_mutex_lock(&philo->data->write);
	ft_printf("data val: %d", philo->data->is_dead);
	pthread_mutex_unlock(&philo->data->write);
	while (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_num)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

/**
 * @brief Routine function for a philosopher thread.
 *
 * This function represents the routine of a philosopher thread. It sets the time
 * when the philosopher should die, creates a supervisor thread to monitor the
 * philosopher's activity, and initiates the eating process. Once the philosopher
 * has died, it joins the supervisor thread and returns.
 *
 * @param philo_ptr A pointer to the philosopher structure.
 *
 * @return NULL.
 */
void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	philo->time_to_die = philo->data->death_time + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->is_dead == 0)
	{
		eat(philo);
		messages(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

/**
 * @brief Initializes threads for the dining simulation.
 *
 * This function initializes threads for the dining simulation. It creates a monitor
 * thread to monitor the dining process and multiple philosopher threads to represent
 * each philosopher. It ensures proper synchronization between threads and handles
 * errors during thread creation and joining.
 *
 * @param data A pointer to the data structure containing information about the dining
 *             simulation.
 *
 * @return An integer representing the success status. Returns 0 on success.
 */
int	thread_init(t_data *data)
{
	int			i;
	pthread_t	t0;

	i = 0;
	data->start_time = get_time();
	if (data->meals_nb > 0)
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (error("ERROR WHILE CREATING THREADS", data));
	while (i < data->philo_num)
	{
		if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[i]))
			return (error("ERROR WHILE CREATING THREADS", data));
		ft_usleep(1);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(data->tid[i], NULL))
			return (error("ERROR WHILE JOINING THREAD", data));
		i++;
	}
	return (0);
}