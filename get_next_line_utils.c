/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:45:09 by jacket            #+#    #+#             */
/*   Updated: 2024/01/03 15:25:22 by jacket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen (const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr++ = 0;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if (!(ptr = (void *) malloc(nmemb * size)))
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ptr;
	size_t			bkplen;

	if (!s1 || !s2)
		return (NULL);
	bkplen = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (unsigned char *) malloc(sizeof(char) * bkplen + 1);
	if (!ptr)
		return (NULL);
	while(*s1)
		*ptr++ = *s1++;
	while(*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	ptr -= bkplen;
	return ((char *)ptr);
}
