/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:13:05 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 14:54:05 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*p;

	p = malloc(ft_strlen(s1) + sizeof(char));
	if (p == NULL)
		return (NULL);
	dst = p;
	while (*s1)
		*dst++ = *s1++;
	*dst = 0;
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*p;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	p = substr;
	while (len--)
		*substr++ = *(s++ + start);
	*substr = 0;
	return (p);
}
