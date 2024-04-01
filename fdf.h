/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:44:30 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/27 16:54:50 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"
# include "./Libft/libft.h"
# include "get_next_line.h"

# define CROSS 17
# define ESCAPE 53
# define H 1080
# define W 1080
# define A 45
# define B 30
# define DST 10

typedef struct s_point
{
	int		value;
	char	*rgb;
	int		x;
	int		y;
	int		new_x;
	int		new_y;
}				t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_data			image;
	t_point			**map;
}				t_vars;

int		key_hook(int keycode, t_vars *vars);
void	mlx_error(int type, t_vars *vars);
int		close_window(t_vars *vars);
void	check_file(char *map);
void	ft_free_two(char *s1, char *s2, int i, t_vars *vars);
void	ft_free_tab(char **tab);
void	free_map(t_vars *vars);
int		so_loop(t_vars *vars);

int		ft_count_lines(char *text);
int		ft_count_columns(char **line);
t_point	**manage_map(char *map, t_vars *vars);
t_point	**ft_create_infotab(char *longstr, t_vars *vars);
t_point	**ft_fill_tab(char *lngstr, t_point **pointinfo, t_vars *vars, int i);
void	ft_filling(int i, int j, t_point **pointinfo, char *line);
void	ft_add_coords(t_point **pointinfo, int i, int j);

int		ft_draw_map(t_point **pointinfo, t_data image, t_vars *vars);
void	ft_calculate_pos(int i, int j, t_point **info, t_vars *vars);
void	ft_pixel_put(t_data *image, int i, int j, t_point **point);

int		ft_horizontal_line(t_point **pointinfo, t_vars *vars);
void	ft_draw_h_line(int i, int j, t_point **point, t_data *image);
int		ft_vertical_line(t_point **pointinfo, t_vars *vars);
void	ft_draw_v_line(int i, int j, t_point **point, t_data *image);
void	line_pixel_put(t_data *image, int x, int y);

int		ft_sign(int n);
int		ft_abs(int n);
void	ft_horizontal(int x, int y, t_data *image, int nextx);
void	ft_vertical(int x, int y, t_data *image, int nexty);
void	ft_more_h_line(t_data *image, t_point point, int nextx, int dy);
void	ft_more_v_line(t_data *image, t_point point, int nexty, int dx);

#endif