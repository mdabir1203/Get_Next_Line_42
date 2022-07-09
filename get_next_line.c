/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:35:10 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/10 00:55:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Here the i variable is maintaining the position
 *        of ending of the buffer.Also +1 is the null bytes.
 *        After each read we create a temp variable to store
 *        each succession of line read.
 *
 * @param inp_buff
 * @return char*
 */

/* static char	*update_buff_store(char *buff_store)
{
    char	*temp_store;
    size_t	i;

    i = 0;
    while (*(buff_store + i) && *(buff_store + i) != '\n')
        i++;
    if (*(buff_store + i) != 0)
    {
        buff_store = NULL;
        free (buff_store);
    }
    else
    {
        temp_store = ft_calloc(temp_buff[i++], sizeof(char));
        temp_buff = temp_store;
    }
    return (temp_buff);
} */

/* static char	*line_chk(char *buff_store)
{
    char	*line;
    size_t	i;

    i = 0;
    line = NULL;
    while (*(temp_buff + i) && *(temp_buff + i) != '\n')
    {
        *(line + i)  = *(temp_buff + i);
        i++;
    }

    /* if(*(line +i) == '\n')
        *(temp_buff + i + 1) = '\n';
    // what should I do //  */

//}

static int read_fd(int fd, char *buff_store, char **line)
{
    char *temp_buff;
    int rd_flag;
    char *found_line;
    int i;
    int count;

    i = 0;
    found_line = ft_strchr(buff_store, '\n');

    if (found_line)
    {
        temp_buff = buff_store;
        *line = malloc(sizeof(char *) * (found_line - temp_buff));
        ft_memcpy(*line, temp_buff, found_line - temp_buff + 1);
        while (temp_buff[i])
        {
            buff_store[i] = *(found_line + i + 1);
            if (*(found_line + i + 1))
                buff_store[i] = *(found_line + i + 1);
            else
                buff_store[i] = 0;
            i++; // Go to the next char
        }
        return (1);
    }
    else
    {
        temp_buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
        count = read(fd, temp_buff, BUFFER_SIZE);
        if (count == 0 && !buff_store)
            return (0); // /Empty file reached*/
        else if (count == 0 && buff_store)
        {
            // END of file && reinitialize the memory
            *line = malloc(sizeof(char *) * ft_strlen(buff_store));
            ft_memcpy(*line,buff_store,ft_strlen(buff_store));
            ft_memset(buff_store,0,ft_strlen(buff_store));
            
            return (-1);
        }
        else
        ft_strlcat(buff_store, temp_buff, count);
        return read_fd(fd, buff_store, line);
    }
    /*     return (NULL);e
    rd_flag = read(fd, rd_str, BUFFER_SIZE);
    while (rd_flag > 0 )
    {
        rd_str[rd_flag] = 0;
        temp_buff = ft_strjoin(buff_store, rd_str);
        buff_store = temp_buff;
        if (ft_strchr(buff_store, '\n'))
            break ;
        rd_flag = read(fd, rd_str, BUFFER_SIZE);
    }
    free (rd_str);
    return (buff_store); */
}

char *get_next_line(int fd)
{
    static char buff_store[BUFFER_SIZE];
    char *temp;
    char *line; // return value
    int rd_flag;

    temp = 0;
    rd_flag = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    rd_flag = read_fd(fd, buff_store, &line);
    if (rd_flag == 1 || rd_flag == -1)
        return (line);
    else
        return (NULL);
    /* temp[1] = *line_chk(buff_store);
    buff_store = update_buff_store(buff_store);
    return (&temp[1]); */
}

#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "get_next_line.h"

int main()
{
  char buffer[20]; // Buffer to store data
  int   stream;
  stream = open("a.txt", O_RDWR);

  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));
  printf("%s",get_next_line(stream));



  
  return(0);
}