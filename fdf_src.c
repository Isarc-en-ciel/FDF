/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:48:00 by iwaslet           #+#    #+#             */
/*   Updated: 2024/03/22 14:34:20 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	fd = 0;
	if (ac != 2)
		exit(1);
	check_file(av[1]);
	vars.map = manage_map(av[1], &vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		mlx_error(0, &vars);
	vars.win = mlx_new_window(vars.mlx, H, W, "FDF");
	if (vars.win == NULL)
		mlx_error(1, &vars);
	vars.image.img = mlx_new_image(vars.mlx, H, W);
	vars.image.addr = mlx_get_data_addr(vars.image.img, &vars.image.bpp,
			&vars.image.line_length, &vars.image.endian);
	ft_draw_map(vars.map, vars.image, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_hook(vars.win, CROSS, 0, &close_window, &vars);
	mlx_loop_hook(vars.mlx, &so_loop, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	so_loop(t_vars *vars)
{
	(void) vars;
	return (1);
}

void	mlx_error(int type, t_vars *vars)
{
	if (type == 1)
		free(vars->win);
	exit(1);
}

void	check_file(char *map)
{
	size_t	i;
	size_t	len;
	char	*fdf;

	i = 0;
	len = ft_strlen(map);
	fdf = ".fdf";
	while (map[len - 4 + i])
	{
		if ((map[len - 4 + i] - fdf[i]) != 0)
		{
			write(1, "invalid file\n", 13);
			exit(1);
		}
		i++;
	}
}
