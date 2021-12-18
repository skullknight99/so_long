/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:53:12 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 16:06:10 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	left(t_vars *vars)
{
	if (vars->s[vars->y / 30][vars->x / 30 - 1] != '1' && \
		(vars->s[vars->y / 30][vars->x / 30 - 1] != 'E' || vars->len < 0))
	{
		printimg(vars, "assets/empty.xpm");
		vars->x = vars->x - 30;
		printimg(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->len--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
	}	
}

void	right(t_vars *vars)
{
	if (vars->s[vars->y / 30][vars->x / 30 + 1] != '1' && \
		(vars->s[vars->y / 30][vars->x / 30 + 1] != 'E' || vars->len < 0))
	{
		printimg(vars, "assets/empty.xpm");
		vars->x = vars->x + 30;
		printimg(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->len--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
	}
}

void	down(t_vars *vars)
{
	if (vars->s[vars->y / 30 + 1][vars->x / 30] != '1' && \
		(vars->s[vars->y / 30 + 1][vars->x / 30] != 'E' || vars->len < 0))
	{
		printimg(vars, "assets/empty.xpm");
		vars->y = vars->y + 30;
		printimg(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->len--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
	}
}

void	up(t_vars*vars)
{
	if (vars->s[vars->y / 30 - 1][vars->x / 30] != '1' && \
		(vars->s[vars->y / 30 - 1][vars->x / 30] != 'E' || vars->len < 0))
	{
		printimg(vars, "assets/empty.xpm");
		vars->y = vars->y - 30;
		printimg(vars, "assets/ryuk.xpm");
		if (vars->s[vars->y / 30][vars->x / 30] == 'C')
		{
			vars->s[vars->y / 30][vars->x / 30] = '0';
			vars->len--;
		}
		else if (vars->s[vars->y / 30][vars->x / 30] == 'E')
			exit(0);
	}
}