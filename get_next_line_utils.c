/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:14:41 by souchane          #+#    #+#             */
/*   Updated: 2023/12/12 14:33:16 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int strchar(char *str, int c)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;    
    }
    if (str[i] == c)
        return 1;
    return 0;    
} ////// static functions

char *sh( char *str)
{
    char *s1;
    int i;
    int len;
    i = 0;
    len = 0;
    while (str[len] != '\0' && str[len] != '\n')
    {
        len++;
    }
    if (str[len] == '\n')
        len++;
    s1 = malloc (len + 1);
    while (i < len)
    {
        s1[i] = str[i];
        i++;
    }
    s1[i] = '\0';
    // free(s1); 
    return (s1);
}