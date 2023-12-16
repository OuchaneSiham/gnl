/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:35:10 by souchane          #+#    #+#             */
/*   Updated: 2023/12/16 19:09:15 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char	*si;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	si = malloc(sizeof(char) * len + 1);
	if (!si)
		return (0);
	while (i < len)
	{
		si[i] = s[start];
		i++;
		start++;
	}
	si[i] = '\0';
	free(s);
	return (si);
}

char	*ssh(char **line)
{
	char	*s1;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((*line)[len] != '\0' && (*line)[len] != '\n')
		len++;
	if ((*line)[len] == '\n')
		len++;
	s1 = malloc (len + 1);
	while (i < len)
	{
		s1[i] = (*line)[i];
		i++;
	}
	s1[i] = '\0';
	(*line) = ft_substr((*line), len, ft_strlen((*line) + len));
	return (s1);
}

char	*gnl(int fd, char **line, char *buffer)
{
	int		r;
	char	*str;

	r = 1;
	while (ft_strchr(*line, '\n') == 0 && r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0 && ft_strlen(*line) == 0)
		{
			if (*line)
				free(*line);
			return (free(buffer), NULL);
		}
		if (r == 0)
			break ;
		buffer[r] = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return (free(buffer), NULL);
	}
	free (buffer);
	str = ssh(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static char	*line[OPEN_MAX];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX
		|| fd >= OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE == INT_MAX)
		buffer = malloc(BUFFER_SIZE);
	else
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = gnl(fd, &line[fd], buffer);
	return (str);
}

// int main()
// {
//     int fd = open("tett2", O_RDONLY);
//     int fd1 = open("tett", O_RDONLY);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd1));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd1));
//      printf("%s\n", get_next_line(fd));
//     printf("%s", get_next_line(fd1));
//      printf("%s\n", get_next_line(fd));
//     printf("%s", get_next_line(fd1));
// }