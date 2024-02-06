/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:02:02 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:11:53 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_unsigned_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = len + printf_unsigned_int(n / 10);
	len = len + printf_char('0' + n % 10);
	return (len);
}
