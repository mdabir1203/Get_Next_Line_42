/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/20 20:58:46 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* This is to copy memory from src to dst. I used memory manipulation 
    as it gives you more freedom compared to strings. But the 
    catch is you have to do allocation properly.
**/

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






/**
 * Here the difficulty was using calloc and getting the right memory 
 * size with memcpy. We have to think about the not only the  '\n'
 * but also the NULL terminator.
 *  
 */
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
			*(buff_store + i) = *(linepos + i + 1);
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
 * This is the get next line function. Used one helper function to
 * to find the newline character and store it in the buffer.
 * Also used a static  var buff_store as it will keep track
 * from reading the text and keep it. If not used static 
 * will lose the records after each call of the function.
 * This can also be done with string functions fully. I prefer
 * memory as it gives me more handling power about performance.
 * Also used a MACRO called MAX_LINE which is to see how much 
 * line is in the input text. We can manipulate it according
 * to the input text lines.Any other suggestions optimizing 
 * please reach out.
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

#include <stdio.h>

int main()
{
// Buffer to store data
  int   stream;
  stream = 0; //open("a.txt", O_RDWR);

  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  return(0);
}