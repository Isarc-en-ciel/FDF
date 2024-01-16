/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:04:52 by iwaslet           #+#    #+#             */
/*   Updated: 2024/01/15 19:22:37 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

void	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		close_window(vars);
}

void	mouse_hook(int code, t_vars *vars)
{
	if (code == CROSS)
		close_window(vars);
}
