/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/05 04:51:52 by mabbas           ###   ########.fr       */
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
 * @brief THis is to duplicate the string
 */
char	*ft_strdup(char *str)
{
	char	*auxstr;
	size_t	size;

	size = ft_strlen(str) + 1;
	auxstr = malloc(sizeof(char) * size);
	if (str == NULL || !auxstr)
		return (NULL);
	while (str[size])
	{
		auxstr[size] = str[size];
		size++;
	}
	auxstr[size] = '\0';
	return (auxstr);
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
	newstring = malloc(sizeof(char) * (total_length + 1));
	if (newstring == NULL)
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

/**
 * @brief Creates a substring to copy it 
 * 		  to the buffer 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	max_len;
	size_t	str_len;
	size_t	sub_len;
	int		i;

	sub_len = 0;
	if (s == NULL)
		return (NULL);
	if ((int) start >= ft_strlen(s))
		return (ft_strdup(""));
	max_len = str_len - start;
	if (max_len < len)
		sub_len = max_len;
	else if (max_len >= len)
		sub_len = len;
	newstr = malloc(sub_len + 1);
	if (newstr == NULL)
		return (0);
	i = 0;
	while (i < max_len)
		newstr[i++] = s[start++];
	newstr[sub_len] = '\0';
	return (newstr);
}
