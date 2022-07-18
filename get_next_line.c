/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:35:10 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/18 18:17:42 by mabbas           ###   ########.fr       */
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

int read_fd(int fd, char *buff_store, char **line)
{
    char *temp_buff;
    char *found_line;
    int i;
    int count;

    i = 0;
    found_line = ft_strchr(buff_store, '\n');
    count = 0;
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
                buff_store[i] = '\0';
            i++; // Go to the next char
        }
        return (1);
    }
    else
    {
        temp_buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
        count = read(fd, temp_buff, BUFFER_SIZE);
        // /Empty file reached*/
        if (count == 0 && !buff_store[0])
            {
                free(temp_buff);
                return (0);
            }
        // /Empty file reached*/
        else if (count == 0 && buff_store[0])
        {
            // END of file && reinitialize the memory
            *line = malloc(sizeof(char *) * ft_strlen(buff_store));
            ft_memcpy(*line,buff_store,ft_strlen(buff_store));
            ft_memset(buff_store,'\0',ft_strlen(buff_store));
            free(temp_buff);
            return (-1);
        }
        else
            {
                ft_strcat(buff_store, temp_buff);
                free(temp_buff);
                return (read_fd(fd, buff_store, line));
            }
    }
    
}

char *get_next_line(int fd)
{
    static char buff_store[BUFFER_SIZE];
    char *temp;
    char *line; // return value
    int rd_flag;

    temp = 0;
    rd_flag = 0;
    if(!buff_store[0])
        ft_memset(buff_store,'\0',BUFFER_SIZE);
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
        return (NULL);
    rd_flag = read_fd(fd, buff_store, &line);
    if (rd_flag == 1 || rd_flag == -1)
        return (line);
    else
        return (NULL);
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
    




//   return(0);
// }