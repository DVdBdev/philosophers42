/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:00:15 by dvan-den          #+#    #+#             */
/*   Updated: 2024/02/06 15:00:15 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	only_one_philo(t_data *data)
{
    data->start_time = get_time();
    if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
        return (error("ERROR WHILE CREATING THREADS", data));
    pthread_detach(data->tid[0]);
    while (data->is_dead == 0)
        ft_usleep(0);
    exit_and_cleanup(data);
    return (0);
}

int	main(int argc, char *argv[])
{
    t_data  data;

    if (argc != 5 && argc != 6)
        return (validate_args_error("Invalid argument count\n"), 1);
    if (validate_args(argv) > 0)
        return (1);
    if (init(&data, argv, argc))
        return (1);
    if (data.philo_num == 1)
		return (only_one_philo(&data));
}