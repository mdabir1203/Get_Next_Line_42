/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/20 16:31:41 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_line(char **ret_line, char buff_store[], int *rd_bytes)
{
	char	*linepos;
	int		i;

	i = 0;
	linepos = ft_strchr(buff_store, '\n');
	if (linepos)
	{
		*ret_line = ft_calloc(sizeof(char), (linepos - buff_store) + 2);
		ft_memcpy(*ret_line, buff_store, linepos - buff_store + 1);
		while (*(linepos + i + 1) != '\0')
		{			
			buff_store[i] = *(linepos + i + 1);
			i++;
		}
		ft_bzero_null(&buff_store[i], MAX_LINE - i);
		return (1);
	}
	if (*rd_bytes == 0)
	{
		*ret_line = ft_calloc(sizeof(char), MAX_LINE + 1);
		ft_memcpy(*ret_line, buff_store, MAX_LINE);
		*rd_bytes = -1;
	}
	return (0);
}
/**
 * @brief 
 *            
 */

char	*get_next_line(int fd)
{
	static char	buff_store[MAX_LINE];
	char		*temp_storage;
	char		*ret_line;
	int			rd_bytes;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	temp_storage = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	rd_bytes = read(fd, temp_storage, BUFFER_SIZE);
	ft_strcat(buff_store, temp_storage);
	free(temp_storage);
	if (rd_bytes < 0 || (rd_bytes <= 0 && buff_store[0] == '\0'))
	{
		ft_bzero_null(buff_store, MAX_LINE);
		return (NULL);
	}
	if (find_line (&ret_line, buff_store, &rd_bytes) == 1)
		return (ret_line);
	if (rd_bytes == -1)
	{
		ft_bzero_null(buff_store, MAX_LINE);
		return (ret_line);
	}
	return (get_next_line(fd));
}

// int main()
// {
// // Buffer to store data
//   int   stream;
//   stream = open("a.txt", O_RDWR);

//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   printf("%s",get_next_line(stream));
//   return(0);
// }