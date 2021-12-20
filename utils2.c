/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:35:16 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 17:44:26 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srx;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	srx = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = srx[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*srx;
	char	*dst;

	srx = (char *)src;
	dst = (char *)dest;
	if (srx == dst || n == 0)
		return (dest);
	if (dst > srx && dst - srx < (int)n)
	{
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = srx[i];
			i--;
		}
		return (dest);
	}
	if (srx > dst && srx - dst < (int)n)
	{
		ft_memcpy(dst, srx, n);
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*t;

	t = (char *)malloc(size * count);
	if (!t)
		return (NULL);
	ft_bzero(t, size * count);
	return (t);
}
