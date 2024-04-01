/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:15:55 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/22 14:33:37 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_horizontal_line(t_point **pointinfo, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while ((i + 1) < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			ft_draw_h_line(i, j, pointinfo, &vars->image);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_draw_h_line(int i, int j, t_point **point, t_data *image)
{
	int		dx;
	int		dy;
	int		dxa;
	int		dya;

	dx = point[i + 1][j].new_x - point[i][j].new_x;
	dy = point[i + 1][j].new_y - point[i][j].new_y;
	dxa = ft_abs(dx);
	dya = ft_abs(dy);
	if (dy == 0)
		ft_horizontal(point[i][j].new_x, point[i][j].new_y, image,
			point[i + 1][j].new_x);
	else if (dx == 0)
		ft_vertical(point[i][j].new_x, point[i][j].new_y, image,
			point[i + 1][j].new_y);
	else if (dxa >= dya)
		ft_more_h_line(image, point[i][j], point[i + 1][j].new_x, dy);
	else
		ft_more_v_line(image, point[i][j], point[i + 1][j].new_y, dx);
}

int	ft_vertical_line(t_point **pointinfo, t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while ((j + 1) < vars->width)
	{
		i = 0;
		while (i < vars->height)
		{
			ft_draw_v_line(i, j, pointinfo, &vars->image);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_draw_v_line(int i, int j, t_point **point, t_data *image)
{
	int		dx;
	int		dy;
	int		dxa;
	int		dya;

	dx = point[i][j + 1].new_x - point[i][j].new_x;
	dy = point[i][j + 1].new_y - point[i][j].new_y;
	dxa = ft_abs(dx);
	dya = ft_abs(dy);
	if (dy == 0)
		ft_horizontal(point[i][j].new_x, point[i][j].new_y, image,
			point[i][j + 1].new_x);
	else if (dx == 0)
		ft_vertical(point[i][j].new_x, point[i][j].new_y, image,
			point[i][j + 1].new_y);
	else if (dxa >= dya)
		ft_more_h_line(image, point[i][j], point[i][j + 1].new_x, dy);
	else
		ft_more_v_line(image, point[i][j], point[i][j + 1].new_y, dx);
}

void	line_pixel_put(t_data *image, int x, int y)
{
	char	*pt;

	pt = NULL;
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		pt = image->addr + ((x * image->line_length)
				+ y * (image->bpp / 8));
		*(unsigned int *)pt = 0xFFFFFF;
	}
}
