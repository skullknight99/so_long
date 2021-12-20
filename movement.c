/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:53:12 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/19 14:03:04 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	left(t_vars *vars)
{
	if (vars->s[vars->y / 30][vars->x / 30 - 1] != '1' && \
		(vars->s[vars->y / 30][vars->x / 30 - 1] != 'E' || vars->col < 0))
	{
		printimages(vars, "assets/empty.xpm");
		vars->x = vars->x - 30;
		printimages(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->col--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
		countmoves();
	}	
}

void	right(t_vars *vars)
{
	if (vars->s[vars->y / 30][vars->x / 30 + 1] != '1' && \
		(vars->s[vars->y / 30][vars->x / 30 + 1] != 'E' || vars->col < 0))
	{
		printimages(vars, "assets/empty.xpm");
		vars->x = vars->x + 30;
		printimages(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->col--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
		countmoves();
	}
}

void	down(t_vars *vars)
{
	if (vars->s[vars->y / 30 + 1][vars->x / 30] != '1' && \
		(vars->s[vars->y / 30 + 1][vars->x / 30] != 'E' || vars->col < 0))
	{
		printimages(vars, "assets/empty.xpm");
		vars->y = vars->y + 30;
		printimages(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->col--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
		countmoves();
	}
}

void	up(t_vars*vars)
{
	if (vars->s[vars->y / 30 - 1][vars->x / 30] != '1' && \
		(vars->s[vars->y / 30 - 1][vars->x / 30] != 'E' || vars->col < 0))
	{
		printimages(vars, "assets/empty.xpm");
		vars->y = vars->y - 30;
		printimages(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->col--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
		countmoves();
	}
}
