/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:04:52 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/22 14:19:41 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->image.img);
	free_map(vars);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		close_window(vars);
	return (0);
}

void	ft_add_coords(t_point **pointinfo, int i, int j)
{
	pointinfo[i][j].x = i;
	pointinfo[i][j].y = j;
}

t_point	**ft_create_infotab(char *longstr, t_vars *vars)
{
	t_point	**pointinfo;

	vars->height = ft_count_lines(longstr);
	pointinfo = malloc(sizeof(t_point *) * (vars->height + 1));
	if (!pointinfo)
	{
		free (longstr);
		mlx_error(1, vars);
	}
	pointinfo[vars->height] = NULL;
	return (pointinfo);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
