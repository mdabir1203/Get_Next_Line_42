/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:35:10 by mabbas            #+#    #+#             */
/*   Updated: 2022/07/05 04:20:55 by mabbas           ###   ########.fr       */
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

static char	*update_buff_store(char *inp_buff)
{
	char	*temp_store;
	size_t	i;

	i = 0;
	while (*(inp_buff + i) && *(inp_buff + i) != '\n')
		i++;
	if (*(inp_buff + i) != 0)
	{
		free (inp_buff);
		inp_buff = NULL;
	}
	else
	{
		temp_store = ft_strdup(inp_buff + i + 1);
		free (inp_buff);
		inp_buff = temp_store;
	}
	return (inp_buff);
}

static char	*line_chk(char *inp_buff)
{
	char	*line;
	size_t	i;

	i = 0;
	while (*(inp_buff + i) && *(inp_buff + i) != (char) 10)
		i++;
	line = ft_substr(inp_buff, 0, i + 1);
	return (line);
}

static char	*read_fd(int fd, char *buff_store, char *rd_str)
{
	char	*temp_buff;
	size_t	bytes;

	bytes = read(fd, rd_str, BUFFER_SIZE);
	if (!buff_store)
		buff_store = ft_strdup("");
	while (bytes > 0)
	{
		rd_str[bytes] = 0;
		temp_buff = ft_strjoin(buff_store, rd_str);
		free (buff_store);
		buff_store = temp_buff;
		if (ft_strchr(buff_store, 10))
			break ;
		bytes = read(fd, rd_str, BUFFER_SIZE);
	}
	free (rd_str);
	return (buff_store);
}

char	*get_next_line(int fd)
{
	static char	*buff_store;
	char		*inp_str;

	inp_str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inp_str[0] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!inp_str[0])
		return (NULL);
	buff_store = read_fd(fd, buff_store, &inp_str[0]);
	if (!buff_store || !buff_store[0])
		return (NULL);
	inp_str[1] = line_chk(buff_store);
	buff_store = update_buff_store(buff_store);
	return (&inp_str[1]);
}
