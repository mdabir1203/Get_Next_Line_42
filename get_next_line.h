/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:49:33 by mabbas            #+#    #+#             */
/*   Updated: 2022/06/28 16:46:09 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
    ** Libraries for malloc,free,write
 */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/**
 * Macros for Buffer size
 * 
 */

# define BUFFER_SIZE 256
# define MAX_FD      1024

/**
 * Helper Functions 
 */


char get_next_line(int fd);
