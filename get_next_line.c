/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/29 16:46:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * @brief This function reads and calculates the size of buffer
 *        Error handling is done if it doesn't read anything
 *        also it means end of file where I reset the offset. 
 * @param head 
 * @param current 
 * @param remain 
 * @return int 
 */
int	rd_size_buffer(t_list **head, t_list *current, char *remains)
{
	current->rd_bytes = read(current->fd, current->buffer, BUFFER_SIZE);
	if (current->rd_bytes < 0)
		return (error_handle (head, current, remains));
	current->offset = 0;
	current->len = 1;
	return (1);
}



/**
 * @brief Might have to typecast to void pointer 
 * 
 * @param fd 
 * @return char* 
 */

char	*get_next_line(int fd)
{
	static	t_list	*head;
	t_list			*current;
	char            *remains;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 \
			|| !find_node(&head, &current, fd))
		return (NULL);
	remains = NULL;
	temp_storage = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	rd_bytes = read(fd, temp_storage, BUFFER_SIZE);
	while (1)
	{
		if (current->offset == BUFFER_SIZE)
			if (!rd_size_buffer(&head, current, remains))
				return (NULL);
		if (current->rd_bytes == 0 || current->offset == (size_t) current->rd_bytes)
			if (!error_handle(&head, current, NULL))
				return (remains);
		if (current->buff[current->offset] == '\n')
			return (str_appen(&head, current, remains, 1));
		if (current->offset == (size_t) current->rd_bytes - 1)
			if (!str_append(&head, current, &remains, 0)
				return (NULL);
		current->offset++;
		current->len++;
	}
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