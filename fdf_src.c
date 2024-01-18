/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_src.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:48:00 by iwaslet           #+#    #+#             */
/*   Updated: 2024/01/18 13:06:29 by iwaslet          ###   ########.fr       */
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

int	ft_free_two(char *s1, char *s2)
{
	if (s1)
		free (s1);
	if (s2)
		free (s2);
}

/*
int	manage_map(char *map, t_vars *vars)
{
	int		fd;
	char	**tab;
	char	**colours;
	char	*coord;

	//check qu'on a un ".fdf"
	fd = open(map, O_RDONLY);
	if (fd == -1)
		mlx_error(0, &vars);
	coord = get_next_line(fd);
	while (coord)
	{
		tab = ft_split(coord, " ");
		int i = 0;
		while (tab[i])
			i++;
		t_point *point = malloc(sizeof(t_point) * (i + 1));
		i = 0;
		while (tab[i])
		{
			//compter les "\n" strchr ?
			
			point[i].value = ft_atoi(tab[i]);
			point[i].rgb = ft_on_de_demerde();
			i++;
		}
		free(coord);
		coord = get_next_line(fd);
		if (!coord)
			break ;
	}
	return (0);
}
*/
