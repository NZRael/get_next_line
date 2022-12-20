/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:48:56 by sboetti           #+#    #+#             */
/*   Updated: 2022/12/20 14:57:01 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *sbase)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (rd != 0 && !ft_strchr(sbase, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		sbase = ft_strjoin(sbase, buff);
	}
	free(buff);
	return (sbase);
}

char	*get_next_line(int fd)
{
	static char	*sbase;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	sbase = ft_read(fd, sbase);
	if (!sbase)
		return (NULL);
	line = ft_getline(sbase);
	sbase = ft_newsbase(sbase);
	return (line);
}
