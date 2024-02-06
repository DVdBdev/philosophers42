/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:18 by dvan-den          #+#    #+#             */
/*   Updated: 2024/02/06 15:01:15 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Validates whether a given string consists only of
 * numeric characters.
 *
 * This function checks if each character in the input string
 * is a numeric character (0-9). If any non-numeric character
 * is encountered, the function returns 1; otherwise,
 * it returns 0.
 *
 * @param arg A pointer to the input string to be validated.
 * @return 1 if the string contains non-numeric characters,
 * 0 otherwise.
 */
static int	validate_only_numbers(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Writes an error message to the standard error
 * output.
 *
 * This function takes an error message string and writes
 * it to the standard error output (stderr). It calculates
 * the length of the input string and uses the `write` system
 * call to output the error message to the standard error.
 * It does not append a newline character to the output.
 *
 * @param err_str A pointer to the null-terminated string
 * containing the error message.
 * @return The number of characters written to the standard
 * error output.
 */
int	validate_args_error(char *err_str)
{
	size_t	len;

	len = ft_strlen(err_str);
	return (write(2, err_str, len));
}

/**
 * @brief Validates command-line arguments for a philosopher
 * simulation.
 *
 * This function validates the command-line arguments provided
 * for a philosopher simulation. It checks the philosophers
 * number, time to die, time to eat, time to sleep, and the
 * optional number of times each philosopher should eat.
 * If any validation fails, it writes an appropriate error
 * message to the standard error output and returns from the 
 * function.
 *
 * @param argv An array of command-line argument strings.
 * @return (0 if all validations pass); otherwise, it returns 
 * the number of characters written to the standard error 
 * output in case of an error.
 */
int	validate_args(char **argv)
{
	if (ft_atoi(argv[1]) > MAX || ft_atoi(argv[1]) <= 0
		|| validate_only_numbers(argv[1]))
		return (validate_args_error("Invalid philosophers number\n"));
	if (ft_atoi(argv[2]) <= 0 || validate_only_numbers(argv[2]))
		return (validate_args_error("Invalid time to die\n"));
	if (ft_atoi(argv[3]) <= 0 || validate_only_numbers(argv[3]))
		return (validate_args_error("Invalid time to eat\n"));
	if (ft_atoi(argv[4]) <= 0 || validate_only_numbers(argv[4]))
		return (validate_args_error("Invalid time to sleep\n"));
	if (argv[5] && (ft_atoi(argv[3]) < 0 || validate_only_numbers(argv[3])))
		return (validate_args_error("Invalid times each philo must eat\n"));
}
