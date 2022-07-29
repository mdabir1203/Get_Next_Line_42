/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:37:02 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/29 20:12:00 by mabbas           ###   ########.fr       */
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

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) str;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	str = (void *) ptr;
	return (str);
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

char	*str_append(t_list **head, t_list *current, char **remains, int choice)
{
	char	*new;

	new = ft_calloc(sizeof (char), current->nw_len + current->len + 1);
	if (!new)
	{
		error_handle(head, current, *remains);
		return (NULL);
	}
	if (*remains)
	{
		ft_strlcpy(new, *remains, current->nw_len + 1);
		free(*remains);
	}
	ft_strlcpy(new + current->nw_len, \
		&current->buffer[1 + current->offset - current->len], current->len + 1);
	current->nw_len += current->len;
	current->len = 1;
	if (choice)
	{
		current->nw_len = 0;
		current->offset++;
		current->len = 1;
	}
	*remains = new;
	return (new);
}					

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		bytes;
	char		*q;
	const char	*p;
	char		ch;

	bytes = 0;
	q = dst;
	p = src;
	ch = '\0';
	while (ch = *(p++))
	{
		if (bytes + 1 < size)
				*q++ = ch;
		bytes++;
	}
	if (size)
		*q = '\0';
	return (bytes);
}
