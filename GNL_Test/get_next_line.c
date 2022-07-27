/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/27 08:31:54 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * @brief Takes the opened file descriptor and saves on a "buff" variable
 * which is read from it. Then concatenates it to the cumulative static 
 * variable for the persistence of the information. Modified Calloc used to
 * initialize with 'NULL' bytes
 * @param File descriptor, Pointer to condition of static var from 
 * 		  previous runs of get_next_line()
 * @return NULL if error or (static  var + buff) joined.
 */

char	*ft_get_buff_line(int fd, char *n_line)
{
	char	*buff;
	int		rd_bytes;

	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	rd_bytes = 1;
	while (!ft_strchr(n_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
	//buff[rd_bytes] = '\0';
		n_line = ft_strcat(n_line, buff);
	}
	free (buff);
}

/*
 * @brief  Extracts the line (Either with line break and '\0'
 *		   or only '\0' when EOF) from static variable.
           BUFFER_SIZE is MACRO used to how many characters 
		   should be read at a same time. Arrays get "downgraded" to 
		   raw Pointers when they ar
		   passed to functions !!             
 */

char	*get_next_line(int fd)
{
	static char	*n_line;
	const char	*rem_line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (0);
	n_line = ft_get_buff_line (fd, rem_line);
	rem_line = ft_rem_line_str(rem_line);
	return (n_line);
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