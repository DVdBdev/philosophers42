/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:26:58 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/27 02:18:55 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_empty_string(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (empty_str)
		empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*substr;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (create_empty_string());
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
