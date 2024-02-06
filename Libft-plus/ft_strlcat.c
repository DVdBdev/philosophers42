/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:19:03 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/19 19:23:03 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	space_left;
	size_t	copy_len;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size <= i)
		return (size + j);
	space_left = size - i - 1;
	if (j < space_left)
		copy_len = j;
	else
		copy_len = space_left;
	k = 0;
	while (k < copy_len)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + copy_len] = '\0';
	return (i + j);
}
