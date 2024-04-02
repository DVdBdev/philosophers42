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

int main(int argc, char *argv[])
{
    t_data  data;

    if (argc != 5 && argc != 6)
        return (validate_args_error("Invalid argument count\n"), 1);
    if (validate_args(argv) > 0)
        return (1);
    if (init(&data, argv, argc))
        return (1);
}