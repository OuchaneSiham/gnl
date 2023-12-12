/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:04:05 by souchane          #+#    #+#             */
/*   Updated: 2023/12/12 18:32:48 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
#include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// int strchar(char *str, int c)
// {
//     int i;
//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == c)
//             return 1;
//         i++;    
//     }
//     if (str[i] == c)
//         return 1;
//     return 0;    
// }
// char *sh( char *str)
// {
//     char *s1;
//     int i;
//     int len;
//     i = 0;
//     len = 0;
//     while (str[len] != '\0' && str[len] != '\n')
//     {
//         len++;
//     }
//     if (str[len] == '\n')
//         len++;
//     s1 = malloc (len + 1);
//     while (i < len)
//     {
//         s1[i] = str[i];
//         i++;
//     }
//     s1[i] = '\0';
//     // free(s1); 
//     return (s1);
// }
# include "get_next_line.h"
char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int len;

    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = 0;
    }
    len = strlen(s1) + strlen(s2);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    strcpy(str, s1);
    strcat(str, s2);
    str[len] = '\0';
    free(s1);
    return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*si;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!len || start >= ft_strlen(s))
		return (free(s), ft_strdup(""));
	slen = ft_strlen(s + start);
	if (slen > len)
		slen = len; 
	si = malloc(sizeof(char) * slen + 1);
	if (!si)
		return (0);
	while (i < slen)
	{
		si[i] = s[start];
		i++;
		start++;
	}
	si[i] = '\0';
    // free(si);
	return (si);
}
char *get_next_line(int fd)
{
    char *buffer;
    char *str;
    static char *line;
    int r;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    r = 1;
    while (strchar(buffer, '\n') == 0 && r)
    {
        r = read(fd, buffer, BUFFER_SIZE);
        if (r <= 0 && ft_strlen(line) == 0)
        {
            free(buffer);
            return NULL;
        }
        buffer[BUFFER_SIZE] = '\0';

        line = ft_strjoin(line, buffer);
    }
    free (buffer);
    str = sh(line);
    line = ft_substr(line, ft_strlen(str), ft_strlen(line + ft_strlen(str)));
    return (str);
}

// void f()
// {
//     system("leaks a.out");
// }

// int main()
// {
//     atexit(f);
//     int fd = open("tett", O_RDONLY);

//     char *str;
//     str = gnl(fd);
//     printf("%s", str);
//     free(str);
//         str = gnl(fd);
//     printf("%s", str);
//         free(str);
//     str = gnl(fd);
//     printf("%s", str);
//     free(str);
//     str = gnl(fd);
//     printf("%s", str);
//     free(str);
//     // while(1);
// }