/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:23:56 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 11:25:54 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	firstRow(char **s)
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

int	lastRow(char **s, int a)
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

int	firstGrid(char **s)
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

int	lastGrid(char **s, int x)
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
	if (firstRow(s) && lastRow(s, reso->y) && \
		firstGrid(s) && lastGrid(s, reso->x))
		return (1);
	else
		return (0);
}