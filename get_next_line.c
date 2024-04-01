/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:01:42 by iwaslet           #+#    #+#             */
/*   Updated: 2024/02/06 17:31:53 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*grab_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc_gnl(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_letgo(char *s)
{
	if (s)
		free(s);
	s = NULL;
	return (NULL);
}

char	*new_buffer(char *str)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_letgo(str));
	new_buffer = ft_calloc_gnl(ft_strlen_gnl(str) - (i));
	if (!new_buffer)
		return (ft_letgo(str));
	while (str[i])
	{
		i++;
		new_buffer[j] = str[i];
		j++;
	}
	free(str);
	return (new_buffer);
}

char	*read_it(char *temp, int fd)
{
	int		n;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_letgo(temp));
	n = 1;
	while (n > 0)
	{
		n = read (fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			if (temp)
				temp = ft_letgo(temp);
			return (ft_letgo(buffer));
		}
		buffer[n] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
		if (!temp)
			return (ft_letgo(buffer));
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = ft_calloc_gnl(1);
	if (temp == NULL)
		return (NULL);
	if (!ft_strchr_gnl(temp, '\n'))
	{
		temp = read_it(temp, fd);
		if (!temp)
			return (ft_letgo(temp));
	}
	line = grab_line(temp);
	if (!line)
	{
		temp = ft_letgo(temp);
		return (NULL);
	}
	temp = new_buffer(temp);
	return (line);
}
