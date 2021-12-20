/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcomp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:42:03 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/20 17:43:56 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	countassets(t_vars *vars, char c)
{
	if (c == 'P')
		vars->player++;
	if (c == 'C')
		vars->col++;
	if (c == 'E')
		vars->exits++;
}

int	checkcomp(t_vars *vars, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			countassets(vars, s[i][j]);
			if (vars->exits > 0 && vars->player == 1 && vars->col > 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
