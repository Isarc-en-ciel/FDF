/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:48:00 by iwaslet           #+#    #+#             */
/*   Updated: 2024/01/16 12:52:27 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	if (ac != 2)
		exit(1);
	manage_map(av[1], &vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (mlx_error(0, &vars));
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "FDF");
	if (vars.win == NULL)
		return (mlx_error(1, &vars));
	mlx_hook(vars.win, CROSS, 0, &mouse_hook, &vars);
	mlx_hook(vars.win, ESCAPE, 0, &key_hook, &vars);
	//mlx_loop_hook(game.mlx, &so_long, &game); fonction pour faire boucler le programme actif
	mlx_loop(vars.mlx);
}

int	mlx_error(int type, t_vars *vars)
{
	if (type == 1)
		free(vars->win);
	return (1);
}

int	manage_map(char *map, t_vars *vars)
{
	int		fd;
	int		i;
	int		j;
	char	**tab;
	char	**colours;
	char	*coord;

	i = 0;
	j = 0;
	//check qu'on a un ".fdf"
	fd = open(map, O_RDONLY);
	if (fd == -1)
		mlx_error(0, &vars);
	coord = get_next_line(fd);
	while (coord)
	{
		tab = ft_split(coord, " ");
		//recuperer les couleurs
		while (tab++)
		{
			tab = ft_atoi(tab);
		}
		j++;
		free(coord);
		coord = get_next_line(fd);
		if (!coord)
			break ;
	}
	return (0);
}
