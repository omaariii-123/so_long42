/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:22:22 by yomari            #+#    #+#             */
/*   Updated: 2022/05/10 13:50:36 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc (sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		str[i] = str2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(str1);
	return (str);
}
