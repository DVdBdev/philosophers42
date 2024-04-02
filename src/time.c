/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:16:34 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/02 14:31:12 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Retrieves the current system time in milliseconds.
 *
 * This function retrieves the current system time in milliseconds using the
 * gettimeofday function. If an error occurs during the time retrieval process,
 * an error message is printed, and the function returns 0.
 *
 * @return uint64_t - The current time in milliseconds since the Epoch.
 */
uint64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE", NULL));
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Suspends execution of the current thread for a specified time.
 *
 * This function suspends the execution of the current thread for the specified
 * amount of time, measured in microseconds. It utilizes the get_time function
 * to measure the elapsed time accurately. If the usleep system call fails, it
 * returns 0.
 *
 * @param time The time, in microseconds, for which to suspend execution.
 *
 * @return int - Returns 0 on success, or -1 if an error occurs.
 */
int	ft_usleep(__useconds_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}