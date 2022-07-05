/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:49:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/05 04:21:09 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
	** Libraries for malloc,free,write,size_t
 */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

/**
 * Helper Functions used in *_utils.c 
 */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * Main Function to use 
 */
char	*get_next_line(int fd);
#endif