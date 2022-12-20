/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:26:28 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/19 00:59:15 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief This is to traverse and locate
 *        the 'newline' character from the input and put the 
 *        lines read each time to the list
 *        It also checks for the specific file descriptor
 */
int	find_node(t_line **head, t_line **current, int fd)
{
	t_line	*temp_buff;

	if (!*head)
	{
		*head = new_node(fd);
		if (!*head)
			return (0);
	}
	temp_buff = *head;
	while (temp_buff && (temp_buff)->fd != fd)
	{
		if (!(temp_buff)->next)
		{
			(temp_buff)->next = new_node(fd);
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
int	rd_size_buffer(t_line **head, t_line *current, char *remains)
{
	current->rd_bytes = read(current->fd, current->buffer, BUFFER_SIZE);
	if (current->rd_bytes < 0)
		return (error_handle (head, current, remains));
	current->offset = 0;
	current->len = 1;
	return (1);
}

int	error_handle(t_line **head, t_line *current, char *str)
{
	t_line	*temp_buff;

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
 * @brief  Get the next line object   
 *         I got 3 helper functions --> str_append,
 *         error_handle, find_node(which means if my my stored character 
 *         found or not) The whole data structure I used is intrusive linked
 *        list which means list node contains next pointer to the next list node,
 *        but no data pointer. The list is embedded in the
 *        linked object itself.
 * 		  N.B>Arrays where you can only modify the value at a position & Linked 
 *        Lists you can also modify the next pointer in addition to the value.
 *        ref: **( means storing sentences in a list)
 *        https://www.data-structures-in-practice.com/intrusive-linked-lists/
 * @return char* 
 */

char	*get_next_line(int fd)
{
	static t_line	*head = NULL;
	t_line			*current;
	char			*remains;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 \
			|| !find_node(&head, &current, fd))
		return (NULL);
	remains = 0;
	while (RELOOP)
	{
		if ((current->offset == BUFFER_SIZE) && \
			(!rd_size_buffer (&head, current, remains)))
			return (NULL);
		if ((current->rd_bytes == 0 || current->offset == \
		(size_t) current->rd_bytes) && (!error_handle(&head, current, NULL)))
			return (remains);
		if (current->buffer[current->offset] == '\n')
			return (str_append(&head, current, &remains, 1));
		if (current->offset == (size_t) current->rd_bytes - 1 \
				&& !str_append(&head, current, &remains, 0))
			return (NULL);
		current->offset++;
		current->len++;
	}
}

// #include <fcntl.h>
// int main()
// {
// // Buffer to store data
//   int   stream;
//   stream = open("b.txt", O_RDONLY);

//   printf("%s",get_next_line(stream));
//   return(0);
// }

// int main()
// {
// 	int fd;
// 	fd = open("a.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	return (0);
// }

// #include <time.h>
// #include<stdio.h>
// #include<fcntl.h>

// int main(void)
// {
// 	int fd;
// 	clock_t start_clk = clock();
// 	fd = open("a.txt", O_RDONLY);
// 	char *str;
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
//  printf("\n\nProcessor time: %Lg sec.\n",
// 	((long double)(clock() - start_clk) / CLOCKS_PER_SEC));
// 	return (0);
// }