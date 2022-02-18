/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 03:26:33 by snicky            #+#    #+#             */
/*   Updated: 2021/11/20 18:08:09 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif 
#include "get_next_line.h"

char    *ret_free(char *word)
{
    if (word[0])
        return (word);
    free(word);
    return (void *)0;  
}

char    *get_next_line(int fd)
{
    static char b[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
    static int  i;
    int         j;
    char        *word;
	char        *word2;
	long        count;
	char        *strj;
    
    if (read(fd, b, 0) != 0 || BUFFER_SIZE <= 0)
        return (void *)0;
    word = malloc (1);
    word[0] = '\0';
    if (b[i] == '\n')
        i++;
	j = 0;
	while (b[i] != '\n')
	{
		if(b[i] == '\0')
	    {
	       count = read(fd, b, BUFFER_SIZE);
	        if (count <= 0)
				return(ret_free(word));
			b[count] = '\0';
			i = 0;
		}
		j = 0;
		while (b[i + j] && b[i + j] != '\n')
			j++;
		word2 = malloc(j + 1 + (b[i + j] == '\n'));
		if (!word2)
			return(ret_free(word));
		j = 0;
		while (b[i] && b[i] != '\n')
			word2[j++] = b[i++];
		if (b[i] == '\n')
			word2[j++] = '\n';
		word2[j] = '\0';
		strj = ft_strjoin(word, word2);
		free(word);
		free(word2);
		word = strj;
	}
    if (j == 0 && b[i] == '\n')
    {
        free(word);
        word = malloc (2);
        word[0] = '\n';
        word[1] = '\0';
    }
    if (word[0])
        return (word);
    free(word);
    return (void *)0;
}
