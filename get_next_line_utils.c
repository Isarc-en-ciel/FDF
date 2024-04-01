/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:02:50 by iwaslet           #+#    #+#             */
/*   Updated: 2024/02/06 17:31:48 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen_gnl(s))
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_calloc_gnl(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lentot;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen_gnl(s1);
	if (!s2)
		return (s1);
	i = -1;
	j = -1;
	lentot = l + ft_strlen_gnl(s2);
	str = ft_calloc_gnl(sizeof(char) * (lentot + 1));
	if (!str)
		return (ft_letgo(s1));
	while (++i < l)
		str[i] = s1[i];
	while ((i + ++j) < (lentot))
		str[i + j] = s2[j];
	free(s1);
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
