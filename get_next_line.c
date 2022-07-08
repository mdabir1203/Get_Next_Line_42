/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:35:10 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/08 06:09:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * @brief Here the i variable is maintaining the position
 *        of ending of the buffer.Also +1 is the null bytes.
 *        After each read we create a temp variable to store
 *        each succession of line read.
 * 
 * @param inp_buff 
 * @return char* 
 */

static char	*update_buff_store(char *temp_buff)
{
	char	*temp_store;
	size_t	i;

	i = 0;
	while (*(temp_buff + i) && *(temp_buff + i) != '\n')
		i++;
	if (*(temp_buff + i) != 0)
	{
		free (temp_buff);
		temp_buff = NULL;
	}
	else
	{
		temp_store = ft_calloc(temp_buff + i + 1);
		inp_buff = temp_store;
	}
	return (temp_buff);
}

static char	*line_chk(char *temp_buff)
{
	char	*line;
	size_t	i;

	i = 0;
	while (*(temp_buff + i) && *(temp_buff + i) != '\n')
    {	
        *(line + i)  = *(temp_buff + i)
        i++;
	{
    
    if(*(temp +i) == '\n')
        *(temp_buff + i) = '\n';
    // what should I do // 
	return (line);
}

static char	*read_fd(int fd, char *buff_store, char *rd_str)
{
	char	*temp_buff;
	int	    rd_flag;

	if(!(temp_buff = calloc(char * BUFFER_SIZE + 1))
        return (NULL);
    rd_flag = read(fd, rd_str, BUFFER_SIZE);
    while (rd_flag > 0 )
	{
		rd_str[rd_flag] = 0;
		temp_buff = ft_strjoin(buff_store, rd_str);
		free (buff_store);
		buff_store = temp_buff;
		if (ft_strchr(buff_store, '\n'))
			break ;
		rd_flag = read(fd, rd_str, BUFFER_SIZE);
	}
	free (rd_str);
	return (buff_store);
}

char	*get_next_line(int fd)
{
	static char	*buff_store;
	char		*temp;

	temp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(temp[0] = ft_calloc((BUFFER_SIZE + 1), sizeof (char))))
		return (NULL);
	if(!(buff_store = read_fd(fd, buff_store, &temp[0]) || !buff_store[0])
		return (NULL);
	temp[1] = *line_chk(buff_store);
	buff_store = update_buff_store(buff_store);
	return (&temp[1]);
}

