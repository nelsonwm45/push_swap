/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:51:18 by nchok             #+#    #+#             */
/*   Updated: 2023/10/27 16:05:06 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_s2;

	i = 0;
	if ((!s1 || !s2) && !n)
		return (NULL);
	if (s2[i] == '\0')
		return ((char *)s1);
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	i = 0;
	while (s1[i] && i + len_s2 <= n)
	{
		j = 0;
		while (j < len_s2 && s1[i + j] == s2[j])
			j++;
		if (j == len_s2)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

// int main(void) {
//     const char *haystack = "Hello, World!";
//     const char *needle1 = "World";
//     const char *needle2 = "lo, ";
//     const char *needle3 = "Earth";

//     // Testing your ft_strnstr
//     char *result1 = ft_strnstr(haystack, needle1, 13);
//     char *result2 = ft_strnstr(haystack, needle2, 13);
//     char *result3 = ft_strnstr(haystack, needle3, 13);

//     printf("Your ft_strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle1, haystack, result1);
//     printf("Your ft_strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle2, haystack, result2);
//     printf("Your ft_strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle3, haystack, result3);

//     // Testing the standard library strnstr
//     char *result4 = strnstr(haystack, needle1, 13);
//     char *result5 = strnstr(haystack, needle2, 13);
//     char *result6 = strnstr(haystack, needle3, 13);

//     printf("Standard Library strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle1, haystack, result4);
//     printf("Standard Library strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle2, haystack, result5);
//     printf("Standard Library strnstr: Search for '%s' in '%s'
//			- Result: %s\n", needle3, haystack, result6);

//     return 0;
// }
