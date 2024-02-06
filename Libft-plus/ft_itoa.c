/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:58 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/26 20:49:27 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(int num)
{
	int	tmp;
	int	dig;

	tmp = num;
	dig = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		dig++;
	}
	return (dig);
}

static void	make_str(int num, int i, char *str, int is_neg)
{
	while (i >= is_neg)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
}

static char	*handle_int_min(void)
{
	char	*min_str;

	min_str = (char *)malloc(12 * sizeof(char));
	if (min_str)
	{
		min_str[0] = '-';
		min_str[1] = '2';
		min_str[2] = '1';
		min_str[3] = '4';
		min_str[4] = '7';
		min_str[5] = '4';
		min_str[6] = '8';
		min_str[7] = '3';
		min_str[8] = '6';
		min_str[9] = '4';
		min_str[10] = '8';
		min_str[11] = '\0';
	}
	return (min_str);
}

char	*ft_itoa(int num)
{
	int		is_neg;
	int		dig;
	char	*str;
	int		i;

	if (num == INT_MIN)
		return (handle_int_min());
	is_neg = 0;
	if (num < 0)
	{
		is_neg = 1;
		num = -num;
	}
	dig = num_digits(num);
	str = (char *)malloc(dig + is_neg + 1);
	if (!str)
		return (NULL);
	i = dig + is_neg - 1;
	make_str(num, i, str, is_neg);
	if (is_neg)
		str[0] = '-';
	str[dig + is_neg] = '\0';
	return (str);
}
