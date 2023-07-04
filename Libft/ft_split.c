/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:47:28 by sde-silv          #+#    #+#             */
/*   Updated: 2023/06/12 16:03:37 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <string.h>
#include <stdio.h>

 Count the number of words;
 	iterate through non-delimiter
 	if delimiter; count and reset the non delimiter iterator
 Malloc a char pointer array for the sizeof(char *) word count + 1(for NULL);
 Find the length of each word and copy to allocated memories(size of char) + 0\;
 	Check for the delimiter at the start and end?
 Point to it using pointers from the array
 Add a NULL at the end of array
*/

static int	arr_length(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			len ++;
		}
		else if (*s == c)
			i = 0;
		s ++;
	}
	return (len);
}

static char	*ft_copy_str(const char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	while (start < len)
	{
		str[i] = s[start];
		i ++;
		start ++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		start;
	size_t	i;
	int		str;

	arr = malloc(sizeof(char *) * (arr_length(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	str = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			arr[str] = ft_copy_str(s, start, i);
			str ++;
			start = -1;
		}
		i++;
	}
	arr[str] = NULL;
	return (arr);
}
/*
int main(void) {
	int			i ;
    char const *s;
    char	**arr;


	s = " Hello World ! ";
	arr = ft_split(s, ' ');
    
    i = 0;
    while (arr[i] != NULL) 
    {
        printf("%s\n", result[i]);
        i ++;
    }
    printf("%s\n", *arr);

    i = 0;
    while (arr[i] != NULL) 
    {
        free(arr[i]);
        i++;
    }
    free(arr);

    return (0);
}
*/
