/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:17:34 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 14:34:04 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	countmoves(t_vars *vars)
{
	static int	i;

	(void)vars;
	printf("count : %d \n", i);
	i++;
}