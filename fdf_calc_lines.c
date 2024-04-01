/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:06 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/28 12:59:39 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

void	ft_horizontal(int x, int y, t_data *image, int nextx)
{
	int	incx;

	incx = ft_sign(nextx - x);
	while (x <= nextx)
	{
		line_pixel_put(image, x, y);
		x += incx;
	}
}

void	ft_vertical(int x, int y, t_data *image, int nexty)
{
	int	incy;

	incy = ft_sign(nexty - y);
	while (y <= nexty)
	{
		line_pixel_put(image, x, y);
		y += incy;
	}
}

void	ft_more_h_line(t_data *image, t_point point, int nextx, int dy)
{
	int	dx;
	int	incy;
	int	x;
	int	y;
	int	error;

	dx = nextx - point.new_x;
	incy = ft_sign(dy);
	dy = dy * incy;
	x = point.new_x;
	y = point.new_y;
	error = (2 * dy) - dx;
	while (x != nextx)
	{
		line_pixel_put(image, x, y);
		if (error > 0)
		{
			y += incy;
			error += (2 * (dy - (ft_sign(dx) * dx)));
		}
		else
			error += (2 * dy);
		x += ft_sign(dx);
	}
}

void	ft_more_v_line(t_data *image, t_point point, int nexty, int dx)
{
	int	dy;
	int	incx;
	int	x;
	int	y;
	int	error;

	dy = nexty - point.new_y;
	incx = ft_sign(dx);
	dx = dx * incx;
	x = point.new_x;
	y = point.new_y;
	error = (2 * dx) - dy;
	while (y != nexty)
	{
		line_pixel_put(image, x, y);
		if (error > 0)
		{
			x += incx;
			error += (2 * (dx - (ft_sign(dy) * dy)));
		}
		else
			error += (2 * dx);
		y += ft_sign(dy);
	}
}
