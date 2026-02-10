/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:37:33 by nchok             #+#    #+#             */
/*   Updated: 2023/11/06 12:24:49 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	i = 0;
	destination = (char *)dst;
	source = (char *)src;
	if ((destination == source) || n == 0)
		return (destination);
	if (destination == NULL && source == NULL)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}

// int main()
// {
//     char src[] = "Hello, World!";
//     char dst1[20];
//     char dst2[20];

//     // Test case 1: Using ft_memcpy
//     ft_memcpy(dst1, src, strlen(src) + 1);
//     printf("Using ft_memcpy: %s\n", dst1);

//     // Test case 2: Using memcpy from the C library
//     memcpy(dst2, src, strlen(src) + 1);
//     printf("Using memcpy: %s\n", dst2);

//     return 0;
// }
