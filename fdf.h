/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:44:30 by iwaslet           #+#    #+#             */
/*   Updated: 2024/01/15 19:25:17 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./Libft/libft.h"
# include "get_next_line.h"

# define CROSS 17
# define ESCAPE 53

typedef struct s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	int	ln;
	int	lg;
}				t_data;

void	key_hook(int keycode, t_vars *vars);
void	mouse_hook(int code, t_vars *vars);
int		mlx_error(int type, t_vars *vars);
void	close_window(t_vars *vars);

#endif