/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:22:24 by mabbas            #+#    #+#             */
/*   Updated: 2022/08/03 12:31:14 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD   10240 // For MAC // depends on PC Type (ulimit -n)
# define REPEAT     1

/*
	** Libraries for malloc,free,write,size_t // khy2714
 */
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

/**
 * Helper Functions used in *_utils.c 
 */

typedef struct str_list
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	ssize_t			rd_bytes;
	size_t			offset;
	size_t			nw_len;
	size_t			len;
	struct str_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_list	*new_node(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		find_node(t_list **head, t_list **current, int fd);
int		error_handle(t_list **head, t_list *current, char *str);
int		rd_size_buffer(t_list **head, t_list *cur, char *remains);
char	*str_append(t_list **head, t_list *current, char **remains, int choice);
void	*ft_memset(void *str, int c, size_t n);

/**
 * Main Function to use
 */
char	*get_next_line(int fd);
#endif
