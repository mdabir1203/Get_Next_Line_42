/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/20 20:53:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	char	str;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief This function helps in initialialization with '\0' bytes 
 */
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

/**
 *  This is to concatenate the strings at the end
 *  It helps in reading and storing the data in 
 *  buffer. 
 */
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
