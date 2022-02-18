/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:40:18 by snicky            #+#    #+#             */
/*   Updated: 2021/11/18 15:00:51 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/file.h>
#include <string.h>

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 10
#endif

size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);

#endif