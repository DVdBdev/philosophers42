/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:37:14 by dvan-den          #+#    #+#             */
/*   Updated: 2024/02/06 14:37:14 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAX 200

#include "../Libft-plus/libft.h"
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				is_dead;
	int				finished;
	t_philo			*philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;

}	t_data;

typedef struct	s_philo
{
	struct s_data	*data;
	pthread_t		tl;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;	
}	t_philo;

// validate_args.c
int	validate_args(char **argv);
int	validate_args_error(char *err_str);

// error.c
int	error(char *str, t_data *data);

// init.c
int	init(t_data *data, char *argv[], int argc);

#endif