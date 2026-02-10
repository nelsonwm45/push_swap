/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:23 by nchok             #+#    #+#             */
/*   Updated: 2023/10/25 17:37:04 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if dstsize = 0; rethink.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if ((!dst || !src) && !dstsize)
		return (0);
	slen = ft_strlen(src);
	i = ft_strlen(dst);
	dlen = i;
	if (dstsize <= i)
		return (dstsize + slen);
	j = 0;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dlen + slen);
}
// int main()
// {
//     char dest[20];
//     const char *src = " World!";
//     size_t initial_length = 6;  // Length of "Hello," in dest

//     // Test case 1: Concatenating a string within the buffer size
//     strcpy(dest, "Hello,");
//     size_t result1 = ft_strlcat(dest, src, sizeof(dest));
//     printf("Result after ft_strlcat (within buffer size):
//			%s, Length: %zu\n", dest, result1);

//     // Test case 2: Concatenating a string that exceeds the buffer size
//     strcpy(dest, "Hello,");
//     size_t result2 = ft_strlcat(dest, src, initial_length);
//     printf("Result after ft_strlcat (exceeds buffer size):
//			%s, Length: %zu\n", dest, result2);

//     // Test case 3: Using strlcat from the C library within the buffer size
//     char dest2[20];
//     strcpy(dest2, "Hello,");
//     size_t result3 = strlcat(dest2, src, sizeof(dest2));
//     printf("Result after strlcat (within buffer size):
//			%s, Length: %zu\n", dest2, result3);

//     // Test case 4: Using strlcat from the C library
//			that exceeds the buffer size
//     char dest3[20];
//     strcpy(dest3, "Hello,");
//     size_t result4 = strlcat(dest3, src, initial_length);
//     printf("Result after strlcat (exceeds buffer size):
//			%s, Length: %zu\n", dest3, result4);

//     return 0;
// }

// war machine

// int		main(void)
// {
// 	char	*dest;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	// memset(dest, 'r', 6);
// // //
// // // // 	// dest[14] = 'a';
// // // // 	// ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
// // // // 	// write(1, "\n", 1);
// // // // 	// write(1, dest, 15);
// // //
// 	memset(dest, 'r', 15);
// 	// printf("%zu\n", strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	// printf("dest = %s\n", dest);

// 	// write(1, dest, 15);
// 	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// }
