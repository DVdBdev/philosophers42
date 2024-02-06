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

// validate_args.c
int	validate_args(char **argv);
int	validate_args_error(char *err_str);

#endif