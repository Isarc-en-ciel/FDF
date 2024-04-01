/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:27:33 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/18 12:29:00 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_two(char *s1, char *s2, int i, t_vars *vars)
{
	if (s1)
		free (s1);
	if (s2)
		free (s2);
	if (i == 1 || i == 0)
		mlx_error(i, vars);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->height)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	vars->map = NULL;
}
