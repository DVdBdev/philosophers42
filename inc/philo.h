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

# include "../Libft-plus/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

struct	s_data;

typedef struct	s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;	
}	t_philo;

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

// validate_args.c
int			validate_args(char **argv);
int			validate_args_error(char *err_str);

// error.c
void		exit_and_cleanup(t_data *data);
int			error(char *str, t_data *data);

// init.c
int			init(t_data *data, char *argv[], int argc);

// time.c
uint64_t	get_time(void);
int			ft_usleep(__useconds_t time);

// threads.c
void 		*routine(void *philo_ptr);
void		*supervisor(void *philo_ptr);
void		*monitor(void *data_ptr);
int			thread_init(t_data *data);

// actions.c
void		eat(t_philo *philo);
void		drop_forks(t_philo *philo);
void		take_forks(t_philo *philo);
void		messages(char *str, t_philo *philo);

#endif