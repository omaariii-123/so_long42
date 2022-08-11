/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:22:03 by yomari            #+#    #+#             */
/*   Updated: 2022/05/10 15:14:44 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"
#include <limits.h>

char	*ft_getrest(char *str)
{
	char			*st;
	int				i;
	unsigned int	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	j = (unsigned int) ft_strlen(str) - i;
	st = (char *) malloc(sizeof (char) * j + 1);
	if (!st)
		return (NULL);
	j = 0;
	while (str[i])
		st[j++] = str[++i];
	st[j] = '\0';
	if (!st || st[0] == '\0' )
	{
		free(st);
		return (NULL);
	}
	return (st);
}

char	*ft_getline(char *str)
{
	char	*st;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	st = (char *) malloc(sizeof (char) * i + 2);
	if (!st)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		st[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		st[i] = '\n';
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	*ft_read(int fd, char *str)
{
	char	*st;
	int		i;

	st = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!st)
		return (NULL);
	i = 1;
	while ((ft_search(str) == 0) && i)
	{
		i = read (fd, st, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(st);
			return (NULL);
		}
		st[i] = '\0';
		str = ft_strjoin(str, st);
	}
	free(st);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*st[OPEN_MAX];
	char		*str;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!st[fd])
	{
		st[fd] = malloc(1);
		st[fd][0] = '\0';
	}
	st[fd] = ft_read(fd, st[fd]);
	if (!st[fd])
	{
		free(st[fd]);
		return (NULL);
	}
	str = ft_getline(st[fd]);
	tmp = st[fd];
	st[fd] = ft_getrest(tmp);
	free(tmp);
	return (str);
}
