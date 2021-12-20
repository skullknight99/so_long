/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:37:29 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/20 11:58:38 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*str_ret(char *stc_arr)
{
	int	i;

	i = 0;
	if (!stc_arr[i])
		return (NULL);
	i = 0;
	while (stc_arr[i] && stc_arr[i] != '\n')
		i++;
	return (ft_substr(stc_arr, 0, i + 1));
}

char	*str_remainder(char *stc_arr, char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!stc_arr)
		return (NULL);
	while (stc_arr[i])
	{
		if (stc_arr[i] == '\n')
		{
			str = ft_substr(stc_arr, i + 1, ft_strlen(stc_arr));
			free(stc_arr);
			if (str[0] == '\n')
			{
				free(s);
				printf("NEWLINE IN MAP!\n");
				exit(0);
			}
			return (str);
		}
		i++;
	}
	free (stc_arr);
	return (NULL);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stc_arr;
	char		*buffer;
	char		*line;
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (!(find_nl(stc_arr)) && (i))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		stc_arr = ft_strjoin(stc_arr, buffer);
	}
	free(buffer);
	line = str_ret(stc_arr);
	stc_arr = str_remainder(stc_arr, line);
	return (line);
}
