/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/18 17:28:59 by mabbas           ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;
	char			*p;

	p = (char *)b;
	count = 0;
	while (count < len)
	{
		p[count] = c ;
		count++;
	}
	p = (void *)b ;
	return (b);
}

/** This is to malloc with 0 bytes. This helps 
 *  in minimizing null terminated string byte errors
 * 
 */

void	*ft_calloc(size_t nelm, size_t elmsize)
{
	void	*inptr;
	size_t	totalsize;

	inptr = NULL;
	totalsize = nelm * elmsize;
	if (nelm && elmsize != (totalsize / nelm))
		return (inptr);
	inptr = malloc(totalsize);
	if (inptr)
		ft_memset (inptr, '\0', totalsize);
	return (inptr);
}

/**
 * @brief This is to locate the 'newline' character in the string
 */
char	*ft_strchr(const char *s, int c)
{
	char	c_match;

	c_match = c;
	while (*s != (char)c_match)
	{
		if (*s == '\0')
			return (NULL);
	++s;
	}
	return ((char *)s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_len)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dest_len)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (dest_len != 0)
	{
		ft_memcpy(dst, src, dest_len -1);
		dst[dest_len -1] = '\0';
	}
	return (srclen);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*csrc;
	char		*cdest;

	csrc  =	(char *)src;
	cdest =	(char *)dst;
	count = -1;
	if ((src != NULL) || (dst != NULL))
	{	
		while (++count < n)
		{
			cdest[count] = csrc[count];
		}
	}
	return (cdest);
}

void	ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
}