/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:45:02 by jacket            #+#    #+#             */
/*   Updated: 2024/01/03 15:11:19 by jacket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_buffer(char *buffer, char *b_read)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, b_read);
	free(buffer);
	return (tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if(!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return(line);
}

char	*get_next(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return(free(buffer), NULL);
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*read_file(char *bf, int fd)
{
	char	*buffer;
	int		b_read;

	if (!bf)
		bf = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buffer), NULL);
		buffer[b_read] = '\0';
		bf = clean_buffer(bf, buffer);
		if(ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (bf);
}

char	*get_next_line(int fd)
{
	static char	*bf;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bf)
		bf = ft_calloc(1, sizeof(char));
	bf = read_file(bf, fd);
	if (!bf)
		return (free(bf), NULL);
	line = get_line(bf);
	bf = get_next(bf);
	return (line);
}
