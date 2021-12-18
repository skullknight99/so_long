/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:12:31 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 15:39:06 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**get_map(char *s)
{
	int		fd;
	char	*lines;
	char	*line;
	int		i;

	i = 0;
	fd = open(s, O_RDONLY);
	line = "";
	lines = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines = ft_strjoin(lines, line);
		free(line);
	}
	free(line);
	close(fd);
	return (ft_split(lines, '\n'));
}

void	printimg(t_vars *vars, char *s)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, s, &vars->b, &vars->d);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
	mlx_destroy_image(vars->mlx, vars->img);
}

void	printe(t_vars *vars, char c)
{
	if (c == '1')
		printimg(vars, "assets/wall.xpm");
	if (c == '0')
		printimg(vars, "assets/empty.xpm");
	if (c == 'P')
	{
		printimg(vars, "assets/ryuk.xpm");
		vars->px = vars->x;
		vars->py = vars->y;
	}
	if (c == 'C')
	{
		printimg(vars, "assets/apple.xpm");
		vars->len++;
	}
	if (c == 'E')
		printimg(vars, "assets/exit.xpm");
}

void	printmap(t_vars *vars, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		vars->x = 0;
		while (s[i][j])
		{
			printe(vars, s[i][j]);
			vars->x += 30;
			j++;
		}
		vars->y += 30;
		i++;
	}
	vars->x = 0;
	vars->y = 0;
}