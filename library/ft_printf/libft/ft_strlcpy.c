/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:41:13 by nchok             #+#    #+#             */
/*   Updated: 2023/10/26 00:31:28 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	i = 0;
	while (src[i] && (i + 1) < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int main()
// {
//     char dest[20];
//     const char *src = "Hello, World!";
//     size_t dstsize = sizeof(dest);

//     // Test case 1: Copying a string within the buffer size
//     size_t result1 = ft_strlcpy(dest, src, dstsize);
//     printf("Result after ft_strlcpy (within buffer size):
//          %s, Length: %zu\n", dest, result1);

//     // Test case 2: Copying a string that exceeds the buffer size
//     char dest2[5];
//     size_t result2 = ft_strlcpy(dest2, src, sizeof(dest2));
//     printf("Result after ft_strlcpy (exceeds buffer size):
//          %s, Length: %zu\n", dest2, result2);

//     // Test case 3: Using strlcpy from the C library within the buffer size
//     char dest3[20];
//     size_t result3 = strlcpy(dest3, src, sizeof(dest3));
//     printf("Result after strlcpy (within buffer size):
//			%s, Length: %zu\n", dest3, result3);

//     // Test case 4: Using strlcpy from the C library
//			that exceeds the buffer size
//     char dest4[5];
//     size_t result4 = strlcpy(dest4, src, sizeof(dest4));
//     printf("Result after strlcpy (exceeds buffer size):
//			%s, Length: %zu\n", dest4, result4);

//     return 0;
// }
