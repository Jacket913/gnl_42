/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:17 by gmoulin           #+#    #+#             */
/*   Updated: 2024/01/11 16:18:19 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Libraries */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/* BUFFER_SIZE for eval*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Functions */

char	*get_next_line(int fd);
size_t		ft_strlen (const char *s);
char	*ft_strdup(const char *s);
void		ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
