/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:51:52 by acmaghou          #+#    #+#             */
/*   Updated: 2021/12/18 13:51:54 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest == NULL)
		return (NULL);
	while (++i < s1_len)
		dest[i] = s1[i];
	while (j <= s2_len)
		dest[i++] = s2[j++];
	free(s1);
	return (dest);
}

static size_t	ft_count_word(char const *s, char c)
{
	int	lword;
	int	words;

	lword = 0;
	words = 0;
	while (s[lword])
	{
		if (s[lword] != c && (s[lword + 1] == c || s[lword + 1] == '\0'))
			words++;
		lword++;
	}
	return (words);
}

static char	**free_word(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free (s);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**word;
	char	*tmp;
	int		lwrd;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	tmp = s;
	word = malloc ((ft_count_word(s, c) + 1) * sizeof (char *));
	if (!word)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		lwrd = 0;
		while (s[lwrd] != c && s[lwrd])
			lwrd++;
		if (*s != c && *s)
			word[j++] = ft_substr(s, 0, lwrd);
		if ((!word[j - 1]) && *s)
			return (free_word(word));
		s += lwrd;
	}
	word[j] = NULL;
	return (free(tmp), word);
}