/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 04:22:32 by yomari            #+#    #+#             */
/*   Updated: 2022/05/10 14:53:36 by yomari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
int		ft_search(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_getline(char *str);
char	*ft_bzero(char *str);
char	*ft_getrest(char *str);

#endif
