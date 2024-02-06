/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:12:20 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/27 02:39:25 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	nbr_of_words(char *s, char c)
{
	int	nbr_of_c;
	int	i;

	i = 0;
	nbr_of_c = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nbr_of_c++;
		}
		else
			i++;
	}
	return (nbr_of_c);
}

static void	free_all(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		str_arr[i] = NULL;
		i++;
	}
	free(str_arr);
}

static char	**splitting(char **str_arr, char *s, char c, int nbr_of)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 0;
	i = 0;
	while (j < nbr_of)
	{
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		str_arr[j] = split_substr(s, i, len);
		if (str_arr[j] == NULL)
		{
			free_all(str_arr);
			return (NULL);
		}
		i = i + len;
		len = 0;
		j++;
	}
	str_arr[nbr_of] = NULL;
	return (str_arr);
}

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	int		word_cnt;

	if (s == NULL)
		return (NULL);
	word_cnt = (nbr_of_words((char *)s, c));
	if (word_cnt == 0)
	{
		str_arr = (char **)malloc(sizeof(char *) * 1);
		if (!str_arr)
			return (NULL);
		str_arr[0] = NULL;
	}
	else
	{
		str_arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
		if (!str_arr)
			return (NULL);
		str_arr = splitting(str_arr, (char *)s, c, word_cnt);
		if (!str_arr)
			return (NULL);
	}
	return (str_arr);
}
