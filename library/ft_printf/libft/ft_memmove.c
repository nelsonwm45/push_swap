/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:46 by nchok             #+#    #+#             */
/*   Updated: 2023/11/06 12:30:16 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source = (const unsigned char *)src;

	destination = (unsigned char *)dst;
	if (destination < source)
	{
		i = 0;
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else if (destination > source)
	{
		i = len;
		while (i > 0)
		{
			destination[i - 1] = source[i - 1];
			i--;
		}
	}
	return (destination);
}

// int main()
// {
//     char src[] = "Hello, 12345, World!";
//     char dst1[30] = "12345, World!";
//     char dst2[30] = "12345, World!";

//     // Test case 1: Using ft_memmove
//     ft_memmove(dst1, src, strlen(src) + 1);
//     printf("Using ft_memmove: %s\n", dst1);

//     // Test case 2: Using memmove from the C library
//     memmove(dst2, src, strlen(src) + 1);
//     printf("Using memmove: %s\n", dst2);

//     return (0);
// }
