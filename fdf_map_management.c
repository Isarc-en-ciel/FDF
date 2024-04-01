/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:51:31 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/15 14:34:56 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**manage_map(char *map, t_vars *vars)
{
	int		fd;
	char	*coord;
	char	*temp;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (1);
	temp = ft_calloc(1, 1);
	if (temp == NULL)
		exit (1);
	coord = get_next_line(fd);
	if (coord == NULL)
		exit (1);
	while (coord)
	{
		if (coord[0] && coord[0] == '\n')
			ft_free_two(temp, coord, 0, vars);
		temp = ft_strjoin_gnl(temp, coord);
		free(coord);
		coord = get_next_line(fd);
	}
	close (fd);
	return (ft_fill_tab(temp, ft_create_infotab(temp, vars), vars, i));
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

t_point	**ft_fill_tab(char *lngstr, t_point **pointinfo, t_vars *vars, int i)
{
	int		j;
	char	**tab;
	char	**tmp;

	tab = ft_split(lngstr, '\n');
	if (!tab)
		ft_free_two(0, lngstr, 0, vars);
	free(lngstr);
	while (tab[++i])
	{
		tmp = ft_split(tab[i], ' ');
		if (!tmp)
			mlx_error(1, vars);
		vars->width = ft_count_columns(tmp);
		pointinfo[i] = malloc(sizeof(t_point) * (vars->width + 1));
		if (!pointinfo[i])
			mlx_error(1, vars);
		j = -1;
		while (tmp[++j])
			ft_filling(i, j, pointinfo, tmp[j]);
		ft_free_tab(tmp);
	}
	ft_free_tab(tab);
	return (pointinfo);
}

void	ft_filling(int i, int j, t_point **pointinfo, char *line)
{
	pointinfo[i][j].value = ft_atoi(line);
	pointinfo[i][j].rgb = "0xFFFFFF";
	if (ft_strchr(line, ','))
		pointinfo[i][j].rgb = ft_strdup(ft_strchr(line, ','));
	ft_add_coords(pointinfo, i, j);
}

int	ft_count_columns(char **line)
{
	int		j;
	char	**temp;

	j = 0;
	temp = line;
	while (temp[j])
		j++;
	return (j);
}
