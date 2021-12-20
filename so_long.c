/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:53:47 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/20 17:54:39 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int keycode, t_vars *vars)
{
	if (keycode == 2)
		right(vars);
	if (keycode == 1)
		down(vars);
	if (keycode == 13)
		up(vars);
	if (keycode == 0)
		left(vars);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		free_all_rows(vars);
		return (0);
	}
	return (0);
}

int	grids(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_all_rows(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->s[i])
	{
		free(vars->s[i]);
		i++;
	}
	free(vars->s);
}

int	red_cross(int keycode, t_vars *vars)
{
	(void)keycode;
	exit(0);
	free_all_rows(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_res	reso;

	(void)ac;
	vars.s = get_map(av[1]);
	reso.x = ft_strlen(vars.s[0]);
	reso.y = grids(vars.s);
	if (!check_map(vars.s, &reso) || !checklen(vars.s))
		return (printf("ERROR MAP"), free_all_rows(&vars), 0);
	if (!checkcomp(&vars, vars.s))
		return (printf("ERROR\nLack of map elems"), free_all_rows(&vars), 0);
	vars.col = -1;
	vars.h = reso.y * 30;
	vars.w = reso.x * 30;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, reso.x * 30, reso.y * 30, "Apples");
	printmap(&vars, vars.s);
	printf("count : 0\n");
	vars.x = vars.px;
	vars.y = vars.py;
	mlx_hook(vars.win, 17, 1L << 2, red_cross, &vars);
	mlx_hook(vars.win, 2, 1L << 0, keys, &vars);
	mlx_loop(vars.mlx);
}
