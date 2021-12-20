/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:51:52 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 17:40:43 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	strs_count(char *str, char c)
{
	size_t	i;
	size_t	num;

	if (!c)
		return (1);
	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			num++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (num);
}

static size_t	next_slen(char *str, char c)
{
	static int	i;
	size_t		len;

	len = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

static char	**generate(char *s, char **res, char c)
{
	size_t	i;
	size_t	arr;

	arr = 0;
	if (!c)
	{
		ft_memmove(res[0], s, ft_strlen(s));
		res[1] = NULL;
		return (res);
	}
	while (*s)
	{
		i = 0;
		while (*s && *s != c)
			res[arr][i++] = *(s++);
		while (*s == c)
			s++;
		arr++;
	}
	res[arr] = NULL;
	return (res);
}

int	allocate_res(char **res, char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!res)
		return (0);
	while (i < strs_count(s, c))
	{
		len = next_slen((char *)s, c);
		res[i++] = ft_calloc(len + 1, sizeof(char));
		if (!(res + i))
		{
			while (i-- > 0)
				free(res[i]);
			return (0);
		}
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	if (!*s)
	{
		res = (char **)malloc(sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc(sizeof(char *) * (strs_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (!allocate_res(res, s, c))
		free(res);
	return (generate(s, res, c));
}
