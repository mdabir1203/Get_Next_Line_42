/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/20 15:26:47 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_line(char **ret_line, char buff_store[], int *rd_bytes)
{
	char	*linepos;
	int     i;

	i = 0;
	linepos = ft_strchr(buff_store, '\n');
	if (linepos)
	{
		*ret_line = ft_calloc(sizeof(char), (linepos - buff_store) + 2);
		ft_memcpy(*ret_line, buff_store, linepos - buff_store + 1);
        //include '\n' && NuLL byte
		while (*(linepos + i + 1) != '\0')
		{			
			buff_store[i] = *(linepos + i + 1);
			i++;
			// next part after strchr iteration
		}
		ft_bzero_null(&buff_store[i], MAX_LINE  - i);
		return (1);
	}
	if(*rd_bytes == 0)
	{
		*ret_line = ft_calloc(sizeof(char), MAX_LINE + 1);
		ft_memcpy(*ret_line, buff_store, MAX_LINE);
		*rd_bytes = -1;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char buff_store[MAX_LINE];
	char		*temp_storage;
	char		*ret_line;
	int			rd_bytes;
	
	if(!buff_store[0])
		ft_bzero_null (buff_store,MAX_LINE);
	 // EOF Reached // Error Handling
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		// (buff_store[0] == 0 && rd_bytes == 0))
		return (NULL);
	temp_storage = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	rd_bytes = read(fd, temp_storage, BUFFER_SIZE);
	 if (rd_bytes < 0  || (rd_bytes <= 0 && buff_store[0] == '\0'))
	{
		free(temp_storage);
        ft_bzero_null (buff_store, MAX_LINE);
		return (NULL);
	}
	ft_strcat(buff_store, temp_storage);
	free(temp_storage);
	// & is used to modify inside func
	if (find_line (&ret_line, buff_store, &rd_bytes) == 1)
		return (ret_line);
	if (rd_bytes == -1)
	{
		ft_bzero_null(buff_store, MAX_LINE);
		return (ret_line);
	}
	// END of line reached 
	return (get_next_line(fd));
		// If  end of line not reached we call func to read again
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