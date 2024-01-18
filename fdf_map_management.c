/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:51:31 by iwaslet           #+#    #+#             */
/*   Updated: 2024/01/18 13:07:00 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	manage_map(char *map, t_vars *vars)
{
	int		fd;
	char	*coord;
	char	*temp;
	
	fd = open(map, O_RDONLY);
	if (fd == -1)
		mlx_error(0, &vars);
	temp = ft_calloc(1, 1);
	coord = get_next_line(fd);
	while (coord)
	{
		if (coord[0] && coord[0] == '\n')
		{
			ft_free_two(temp, coord);
			mlx_error(0, &vars);
		}
		temp = ft_strjoin_gnl(temp, coord);
		free(coord);
		coord = get_next_line(fd);
	}
	ft_fill_tab(temp);
	free (temp);
	return (0);
}

int	ft_count_lines(char *text)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (text[i])
	{
		if (text[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	ft_fill_tab(char *lngstr) // ajouter t_point en param ?
{
	int		i;
	int		count;
	char	**tab;
	char	**tmp;

	i = 0;
	count = ft_count_lines(lngstr);
	t_point **gigapoint = malloc(sizeof(t_point *) * (count + 1));
	tab = ft_split(lngstr, '\n');
	free(lngstr);
	while (tab[i])
	{
		tmp = ft_split(tab[i], ' ');
		int j = 0;
		while (tmp[j])
			j++;
		gigapoint[i] = malloc(sizeof(t_point) * (j + 1));
		j = 0;
		while (tmp[j])
		{
			gigapoint[i][j].value = ft_atoi(tmp[j]);
			gigapoint[i][j].rgb = "0xFFFFFF";
			if (ft_strchr(tmp[j], ','))
			{
				gigapoint[i][j].rgb = ft_strdup(ft_strchr(tmp[j], ','));
			}
			j++;
		}
		free (tmp);
		i++;
	}
	return(0);
}
