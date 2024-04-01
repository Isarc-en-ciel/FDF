/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:44:50 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/27 12:50:21 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw_map(t_point **pointinfo, t_data image, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			ft_calculate_pos(i, j, pointinfo, vars);
			ft_pixel_put(&image, i, j, pointinfo);
			j++;
		}
		i++;
	}
	ft_horizontal_line(pointinfo, vars);
	ft_vertical_line(pointinfo, vars);
	return (0);
}

void	ft_pixel_put(t_data *image, int i, int j, t_point **point)
{
	char	*pt;
	int		x;
	int		y;

	pt = NULL;
	x = point[i][j].new_x;
	y = point[i][j].new_y;
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		pt = image->addr + ((x * image->line_length)
				+ y * (image->bpp / 8));
		*(unsigned int *)pt = 0xFFFFFF;
	}
}

void	ft_calculate_pos(int i, int j, t_point **info, t_vars *vars)
{
	float	ca;
	float	sa;
	float	sb;

	ca = cosf(A);
	sa = sinf(A);
	sb = sinf(B);
	info[i][j].new_x = -DST * ((sa
				* sb * (float)(info[i][j].x
					- (vars->width / 2))) + (ca
				* sb * (float)(info[i][j].y
					- (vars->height / 2))) + (ca
				* (float)info[i][j].value)) + (W / 2);
	info[i][j].new_y = -DST * (-sb
			* (float)(info[i][j].x - (vars->width / 2)) + sb
			*(float)(info[i][j].y - (vars->height / 2))) + (H / 2);
}
