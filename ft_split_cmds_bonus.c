/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 05:54:01 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:10 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_nbr_words2(char const *s1, char c)
{
	size_t	nbr_wrds;

	nbr_wrds = 0;
	while (*s1)
	{
		while (*s1 != c && *s1 != 39 && *s1)
			s1++;
		nbr_wrds++;
		while (*s1 == c && c != 0)
			s1++;
		if (*s1 == 39)
		{
			s1++;
			while (*s1 != 39 && *s1)
				s1++;
			if (*s1 == 39)
				s1++;
			nbr_wrds++;
		}
		while (*s1 == c && c != 0)
			s1++;
	}
	return (nbr_wrds);
}

static int	ft_lenchar2(char *s1, char c)
{
	int	j;

	j = 0;
	while (*s1 != c && *s1 != 39 && *s1++)
		j++;
	return (j);
}

static const char	*is_it_single_quote(char **wrds, const char *s1, int i)
{
	int	j;

	j = ft_lenchar2((char *)s1, 39);
	wrds[i] = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (*s1 && *s1 != 39)
		wrds[i][j++] = *s1++;
	wrds[i][j] = '\0';
	if (*s1 == 39)
		s1++;
	return (s1);
}

static char	**ft_aux_split2(size_t nbr_wrds, char const *s1,
	char c, char **wrds)
{
	int	i;
	int	j;

	i = 0;
	while (nbr_wrds--)
	{
		j = ft_lenchar2((char *)s1, c);
		wrds[i] = malloc(sizeof(char) * (j + 1));
		if (!wrds[i])
			free_path_error(wrds);
		j = 0;
		while (*s1 != c && *s1 != 39 && *s1)
			wrds[i][j++] = *s1++;
		wrds[i][j] = '\0';
		while (*s1 == c && *s1)
			s1++;
		if (*s1 == 39 && nbr_wrds--)
			s1 = is_it_single_quote(wrds, ++s1, ++i);
		while (*s1 == c && *s1)
			s1++;
		i++;
	}
	wrds[i] = NULL;
	return (wrds);
}

char	**ft_split_cmds(char const *s1, char c)
{
	size_t	nbr_wrds;
	char	**words;

	if (!s1)
		return (NULL);
	while (*s1 == c && *s1)
		s1++;
	nbr_wrds = ft_nbr_words2(s1, c);
	words = malloc(sizeof(char *) * (nbr_wrds + 1));
	if (!words)
		return (NULL);
	words = ft_aux_split2(nbr_wrds, s1, c, words);
	return (words);
}
