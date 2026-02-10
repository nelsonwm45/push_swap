/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:21:23 by nchok             #+#    #+#             */
/*   Updated: 2023/10/24 18:15:46 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char str[] = "This is a test string.";
//     int c = 'a';
//     size_t n = strlen(str);

//     // Testing your ft_memchr
//     char *result1 = ft_memchr(str, c, n);
//     if (result1 != NULL) {
//         printf("ft_memchr:
//				Character '%c' found at position %ld\n", c, result1 - str);
//     } else {
//         printf("ft_memchr: Character '%c' not found\n", c);
//     }

//     // Testing the standard library memchr
//     char *result2 = memchr(str, c, n);
//     if (result2 != NULL) {
//         printf("Standard Library memchr:
//				Character '%c' found at position %ld\n", c, result2 - str);
//     } else {
//         printf("Standard Library memchr: Character '%c' not found\n", c);
//     }

//     return 0;
// }
