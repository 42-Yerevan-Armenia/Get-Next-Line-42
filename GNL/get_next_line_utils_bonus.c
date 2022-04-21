/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:22:22 by arakhurs          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:28 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[j ++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[j++] = s2[i];
		i++;
	}
	s[j] = 0;
	if (s1)
		free(s1);
	return (s);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!*s || !s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	substr = (char *)malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (0);
	i = 0;
	while (s[start] && i < j)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s || !s1)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
