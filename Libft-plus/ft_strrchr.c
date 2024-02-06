/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:31:12 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/27 01:50:32 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	target;
	char			*last;

	target = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == target)
			last = (char *)s;
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (last);
}
