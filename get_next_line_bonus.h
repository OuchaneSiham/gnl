/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:36:53 by souchane          #+#    #+#             */
/*   Updated: 2023/12/15 17:46:50 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ssh(char **str);
char	*get_next_line(int fd);
char	*gnl(int fd, char **line, char *buffer);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);

#endif