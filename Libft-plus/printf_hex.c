/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:42 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:10:30 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	put_hex(unsigned int n, char format)
{
	const char	*hex_chars;

	if (format == 'x')
		hex_chars = "0123456789abcdef";
	else
		hex_chars = "0123456789ABCDEF";
	if (n >= 16)
		put_hex(n / 16, format);
	printf_char(hex_chars[n % 16]);
}

int	printf_hex_lower(unsigned int n)
{
	put_hex(n, 'x');
	return (hex_len(n));
}

int	printf_hex_upper(unsigned int n)
{
	put_hex(n, 'X');
	return (hex_len(n));
}
