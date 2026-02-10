/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:16:43 by nchok             #+#    #+#             */
/*   Updated: 2023/10/24 17:58:25 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// int main()
// {
//     char buffer1[20];
//     char buffer2[20];

//     // Test case 1: Using ft_bzero
//     strcpy(buffer1, "Hello, World!");
//     printf("Before ft_bzero: %s\n", buffer1);
//     ft_bzero(buffer1, sizeof(buffer1));
//     printf("After ft_bzero: %s\n", buffer1);

//     // Test case 2: Using bzero from the C library
//     strcpy(buffer2, "Hello, World!");
//     printf("Before bzero: %s\n", buffer2);
//     bzero(buffer2, sizeof(buffer2));
//     printf("After bzero: %s\n", buffer2);

//     return 0;
// }
