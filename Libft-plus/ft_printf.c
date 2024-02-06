/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:01:18 by dvan-den          #+#    #+#             */
/*   Updated: 2023/11/10 10:45:11 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printf_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = len + printf_char(va_arg(args, int));
	else if (format == 's')
		len = len + printf_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = len + printf_int(va_arg(args, int));
	else if (format == 'u')
		len = len + printf_unsigned_int(va_arg(args, unsigned int));
	else if (format == '%')
		len = len + printf_percent();
	else if (format == 'x')
		len = len + printf_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		len = len + printf_hex_upper(va_arg(args, unsigned int));
	else if (format == 'p')
		len = len + printf_pointer(va_arg(args, void *));
	return (len);
}

int	valid_specifier(int c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (valid_specifier(str[i + 1]))
				len = len + printf_formats(args, str[i + 1]);
			else
				len = len + printf_char(str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			len = len + printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
