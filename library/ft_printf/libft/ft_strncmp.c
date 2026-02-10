/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:52:36 by nchok             #+#    #+#             */
/*   Updated: 2023/10/26 00:06:30 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//     const char *str1 = "Hello, world!";
//     const char *str2 = "Hello, there!";
//     size_t n = 6;  // Number of characters to compare

//     int custom_result = ft_strncmp(str1, str2, n);
//     int standard_result = strncmp(str1, str2, n);

//     if (custom_result < 0) {
//         printf("Custom ft_strncmp: First %ld characters differ.\n", n);
//     } else if (custom_result == 0) {
//         printf("Custom ft_strncmp: First %ld characters are the same.\n", n);
//     } else {
//         printf("Custom ft_strncmp: First %ld characters differ.\n", n);
//     }

//     if (standard_result < 0) {
//         printf("Standard strncmp: First %ld characters differ.\n", n);
//     } else if (standard_result == 0) {
//         printf("Standard strncmp: First %ld characters are the same.\n", n);
//     } else {
//         printf("Standard strncmp: First %ld characters differ.\n", n);
//     }

//     return 0;
// }
