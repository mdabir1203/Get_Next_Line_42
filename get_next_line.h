/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:49:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/18 17:27:51 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/*
	** Libraries for malloc,free,write,size_t
 */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
/**
 * Helper Functions used in *_utils.c 
 */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_strcat(char *dst, const char *src);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dest_len);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nelm, size_t elmsize);
void	*ft_memset(void *b, int c, size_t len);
char	*line_chk(char *temp_buff);
int	    read_fd(int fd, char *buff_store, char **line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * Main Function to use 
 */
char	*get_next_line(int fd);
#endif