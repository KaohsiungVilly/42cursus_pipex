/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:50:12 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 14:44:08 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (*str++)
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;

	length = ft_strlen(src);
	if (dstsize == 0)
		return (length);
	else if (!*src)
	{
		*dst = '\0';
		return (length);
	}
	while (--dstsize && *src)
		*dst++ = *src++;
	if (length != 0)
		*dst = '\0';
	return (length);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;

	length = ft_strlen(src) + ft_strlen(dst);
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	dstsize -= ft_strlen(dst);
	while (*dst)
		dst++;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	if (length != 0)
		*dst = '\0';
	return (length);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	size_t	length;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	length = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((length + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	ft_strlcat(p, s2, length + 1);
	return (p);
}
