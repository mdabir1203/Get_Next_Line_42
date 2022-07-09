/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/09 21:45:28 by mabbas           ###   ########.fr       */
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

/**
 * @brief This function is used to join the strings
 * 		  Apparently used here to join the buffer of
 * 		  strings read.
 */
char	*ft_strjoin(char const *string1, char const *string2)
{
	char	*newstring;
	size_t	total_length;
	int		ind;
	int		ind2;

	total_length = 0;
	if (!string1 || !string2)
		return (NULL);
	total_length = ft_strlen(string1) + ft_strlen(string2);
	if (!(newstring = malloc(sizeof(char) * total_length + 1)))
		return (NULL);
	ind = -1;
	while (string1[++ind])
	{
		newstring[ind] = string1[ind];
	}
	ind2 = -1;
	while (string2[++ind2])
		newstring[ind++] = string2[ind2];
	newstring[total_length] = '\0';
	return (newstring);
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
