/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/29 20:10:49 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * @brief This is to locate the 'newline' character from the input and put the 
 *        lines read each time to the list
 */
int	find_node(t_list **head, t_list **current, int fd)
{
	t_list	*temp_buff;

	if (!*head)
	{
		*head = new_node(fd);
		if (!*head)
			return (0);
	}
	temp_buff = *head;
	// It creates a new node for a temporary buffer for each file descriptors.
	while (temp_buff && (temp_buff)->fd != fd)
	{
		if (!(temp_buff)->next)
		{
			(temp_buff)->next = new_node(fd);
			if (!(temp_buff)-> next)
				return (0);
		}
		temp_buff = (temp_buff)->next;
	}
	*current = temp_buff;
	return (1);
}

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

int	error_handle(t_list **head, t_list *current, char *str)
{
	t_list	*temp_buff;

	if (str)
		free (str);
	temp_buff = *head;
	if (temp_buff == current)
	{
		*head = temp_buff->next;
		free(current);
		return (0);
	}
	while (temp_buff->next)
	{
		if (temp_buff->next == current)
		{
			temp_buff->next = current->next;
			free(current);
			break ;
		}
		temp_buff = temp_buff->next;
	}
	return (0);
}

/**
 * @brief Might have to typecast to void pointer 
 * 
 * @param fd 
 * @return char* 
 */

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*current;
	char			*remains;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 \
			|| !find_node(&head, &current, fd))
		return (NULL);
	head = NULL;
	while (1)
	{
		if (current->offset == BUFFER_SIZE)
		{
			if (!rd_size_buffer(&head, current, remains))
				return (NULL);
		}
		if (current->rd_bytes == 0 || current->offset == \
									(size_t) current->rd_bytes)
		{
			if (!error_handle(&head, current, NULL))
				return (remains);
		}
		if (current->buffer[current->offset] == '\n')
			return (str_append(&head, current, &remains, 1));
		if (current->offset == (size_t) current->rd_bytes - 1)
		{
			if (!str_append(&head, current, &remains, 0))
				return (NULL);
		}
		current->offset++;
		current->len++;
	}
}

int main()
{
// Buffer to store data
  int   stream;
  stream = 0; //open("a.txt", O_RDWR);

  printf("%s",get_next_line(stream));
  return(0);
}