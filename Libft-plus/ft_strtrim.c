/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:35:46 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/27 02:34:56 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(unsigned char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	find_start(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!char_is_in_set(str[i], set))
			return (i);
		i++;
	}
	return (i);
}

static int	find_end(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (!char_is_in_set(str[i], set))
			return (i);
		i--;
	}
	return (i);
}

static char	*create_empty_string(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (empty_str)
		empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;
	int		len;

	if (s1 == NULL)
		return (create_empty_string());
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end)
		return (create_empty_string());
	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end && start != len)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
