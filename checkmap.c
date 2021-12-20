/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:23:56 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/20 16:38:37 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	first_row(char **s)
{
	int	i;

	i = 0;
	while (s[0][i])
	{
		if (s[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	last_row(char **s, int a)
{
	int	i;

	i = 0;
	a--;
	while (s[a][i])
	{
		if (s[a][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	first_grid(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	last_grid(char **s, int x)
{
	int	i;

	x--;
	i = 0;
	while (s[i])
	{
		if (s[i][x] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **s, t_res *reso)
{
	if (!(first_row(s) && last_row(s, reso->y) && \
		first_grid(s) && last_grid(s, reso->x)))
		return (0);
	return (1);
}
