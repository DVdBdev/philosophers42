/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:28:32 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/27 01:48:06 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	target;

	target = (unsigned char)c;
	while (*str)
	{
		if (*str == target)
			return ((char *)str);
		str++;
	}
	if (target == '\0')
		return ((char *)str);
	return (NULL);
}
