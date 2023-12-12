/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:57:31 by souchane          #+#    #+#             */
/*   Updated: 2023/12/12 18:33:02 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

char *sh( char *str);
char *get_next_line(int fd);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strdup(const char *s1);
char *ft_strjoin(char *s1, char *s2);
int  strchar(char *str, int c);
size_t ft_strlen(const char *s);


#endif