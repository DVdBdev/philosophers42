/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:45 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:09:50 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printf_positive_int(int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + printf_positive_int(n / 10);
	len = len + printf_char('0' + n % 10);
	return (len);
}

int	printf_int(int n)
{
	int		len;
	char	*int_min_str;

	len = 0;
	int_min_str = "-2147483648";
	if (n == INT_MIN)
		len = printf_string(int_min_str);
	else
	{
		if (n < 0)
		{
			len = len + write(1, "-", 1);
			n = -n;
		}
		len = len + printf_positive_int(n);
	}
	return (len);
}
