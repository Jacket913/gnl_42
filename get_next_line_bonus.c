/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:45:02 by jacket            #+#    #+#             */
/*   Updated: 2024/01/03 21:12:17 by jacket           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_buffer(char *sbuffer, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(sbuffer, buffer);
	free(sbuffer);
	return (tmp);
}

char	*get_line(char *sbuffer)
{
	char	*line;
	int		i;

	i = 0;
	if(!sbuffer[i])
		return (NULL);
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
	{
		line[i] = sbuffer[i];
		i++;
	}
	if (sbuffer[i] == '\n')
		line[i] = '\n';
	return(line);
}

char	*get_next(char *sbuffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (sbuffer[i] && sbuffer[i] != '\n')
		i++;
	if (!sbuffer[i])
		return(free(sbuffer), NULL);
	line = ft_calloc((ft_strlen(sbuffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (sbuffer[i])
		line[j++] = sbuffer[i++];
	free(sbuffer);
	return (line);
}

char	*read_file(char *sbuffer, int fd)
{
	char	*buffer;
	int		b_read;

	if (!sbuffer)
		sbuffer = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buffer), NULL);
		buffer[b_read] = '\0';
		sbuffer = clean_buffer(sbuffer, buffer);
		if(ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (sbuffer);
}

char	*get_next_line(int fd)
{
	static char	*sbuffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!sbuffer)
		sbuffer = ft_calloc(1, sizeof(char));
	sbuffer = read_file(sbuffer, fd);//Try to combine 101 && 102 as usual
	if (!sbuffer)
		return (free(sbuffer), NULL);
	line = get_line(sbuffer);
	sbuffer = get_next(sbuffer);
	return (line);
}
