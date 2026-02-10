/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:29:31 by nchok             #+#    #+#             */
/*   Updated: 2023/10/24 18:22:44 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//     char str3[] = "Hello, World!!";
//     size_t n1 = 13;
//     size_t n2 = 14;

//     // Testing your ft_memcmp
//     int result1 = ft_memcmp(str1, str2, n1);
//     int result2 = ft_memcmp(str1, str3, n2);

//     printf("Your ft_memcmp: Compare str1 and str2,
//			n = %zu, result = %d\n", n1, result1);
//     printf("Your ft_memcmp: Compare str1 and str3,
//			n = %zu, result = %d\n", n2, result2);

//     // Testing the standard library memcmp
//     int result3 = memcmp(str1, str2, n1);
//     int result4 = memcmp(str1, str3, n2);

//     printf("Standard Library memcmp: Compare str1 and str2,
//			 n = %zu, result = %d\n", n1, result3);
//     printf("Standard Library memcmp: Compare str1 and str3,
//			n = %zu, result = %d\n", n2, result4);

//     return 0;
// }
