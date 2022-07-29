/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/29 16:46:05 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
 * @brief This Function is used to create nodes to store all
 *        the lines read each time and initialize within the
 *        struct . We are using an Intrusive Linked list
 *        which means the pointer next points to the next node
 *        Offset means no of bytes a member is positioned
 *        from the beginning. Which helps us finding difference
 *        between the length of read and unread lines.
 
 */
t_list	*new_node(int fd)
{
	t_list	*new;

	new = ft_calloc(7, sizeof(t_list));
	new->fd = fd;
	new->rd_bytes = BUFFER_SIZE;
	new->offset = BUFFER_SIZE;
	new->nw_len = 0;
	new->len = 1;
	new->next = NULL;
	return (new);
}

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

int	error_handle(t_list **head, t_list *current, char *str)
{
	t_list	*temp_buff;

	if (str)
		free (str);
	temp_buff = *head;
	if (temp_buff == current)
	{
		*head = temp_buff->next;
		//free(current);
		return (0);
	}
	while (temp_buff->next)
	{
		if (temp_buff->next == current)
		{
			temp_buff->next = current->next;
			//free(current);
			break;
		}
		temp_buff = temp_buff->next;
	}
	return (0);
}

char *str_append(t_list **head, t_list *current, char **remains, int reset_val)
{
	char *new;
	
	new = ft_calloc(current->new_len + current->len + 1);
	if (!new)
	{
		error_handle(head,current,*remains)
		return (NULL);
	}
	if (*remain)
	{
		ft_strlcpy(new, *remains, current->new_len + 1);
		//free(*res);
	}
	ft_strlcpy(new + current->new_len, \
		&current->buffer[1 + current->offset - current->len, current->len + 1);

	current->nw_len += current->len;
	current->len = 1;
	
	if (reset_val)
	{
		current->new_len = 0;
		current->offset++;
		current->len = 1;
	} 
	*remains = new;
	return (new);
}					



size_t	ft_strlcpy(char *dst, const char *src, size_t dest_len)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dest_len)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (dest_len != 0)
	{
		ft_memcpy(dst, src, dest_len -1);
		dst[dest_len -1] = '\0';
	}
	return (srclen);
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
