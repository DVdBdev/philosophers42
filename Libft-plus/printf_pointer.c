/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:53 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/24 00:11:12 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned long long n)
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

static void	put_hex(unsigned long long n)
{
	const char	*hex_chars;

	hex_chars = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16);
	printf_char(hex_chars[n % 16]);
}

int	printf_pointer(void	*ptr)
{
	if (ptr == NULL)
		return (printf_string("(nil)"));
	printf_string("0x");
	put_hex((unsigned long long)ptr);
	return (hex_len((unsigned long long)ptr) + 2);
}
