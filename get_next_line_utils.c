/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:16:40 by sboetti           #+#    #+#             */
/*   Updated: 2022/12/21 17:28:45 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *sbase, char *buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!sbase)
		sbase = ft_calloc(1, 1);
	if (!sbase || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(sbase) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (sbase)
		while (sbase[++i] != '\0')
			str[i] = sbase[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(sbase) + ft_strlen(buff)] = '\0';
	free(sbase);
	return (str);
}

char	*ft_getline(char *sbase)
{
	int		i;
	char	*str;

	i = 0;
	if (!sbase[i])
		return (NULL);
	while (sbase[i] != '\n' && sbase[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (sbase[i] && sbase[i] != '\n')
	{
		str[i] = sbase[i];
		i++;
	}
	if (sbase[i] == '\n')
	{
		str[i] = sbase[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_newsbase(char *sbase)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (sbase[i] && sbase[i] != '\n')
		i++;
	if (!sbase[i])
	{
		free(sbase);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(sbase) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	x = 0;
	while (sbase[i])
		str[x++] = sbase[i++];
	str[x] = '\0';
	free(sbase);
	return (str);
}
