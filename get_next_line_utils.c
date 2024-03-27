/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:30:52 by hienguye          #+#    #+#             */
/*   Updated: 2024/01/20 14:30:53 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int character)
{
	const char	*res;

	res = str;
	while (*res)
	{
		if (*res == (char)character)
			return ((char *)res);
		res++;
	}
	if (character == '\0')
		return ((char *)res);
	return (NULL);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	unsigned char	*res;
	size_t			i;
	size_t			total;

	i = 0;
	total = num_elements * element_size;
	res = (unsigned char *) malloc(total);
	if (res == NULL)
		return (NULL);
	while (i < total)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)res);
}

char	*ft_strdup(char *str)
{
	char		*res;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(str);
	res = (char *) malloc (sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}