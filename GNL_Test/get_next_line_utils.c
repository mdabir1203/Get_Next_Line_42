/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/20 16:34:38 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_null(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
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
		ft_bzero_null (inptr, totalsize);
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*csrc;
	char		*cdest;

	csrc = (char *)src;
	cdest = (char *)dst;
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
