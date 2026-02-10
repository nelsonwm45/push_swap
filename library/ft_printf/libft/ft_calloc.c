/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:32:18 by nchok             #+#    #+#             */
/*   Updated: 2023/11/06 12:13:04 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (UINT_MAX / size))
		return (NULL);
	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

// int	main(void)
// {
// 	size_t num_elements = 5;
// 	size_t element_size = sizeof(int);

// 	// Test case 1: Using ft_calloc
// 	int *arr1 = (int *)ft_calloc(num_elements, element_size);
// 	if (arr1)
// 	{
// 		printf("Memory allocated using ft_calloc: ");
// 		for (size_t i = 0; i < num_elements; ++i)
// 		{
// 			printf("%d ", arr1[i]);
// 		}
// 		printf("\n");

// 		free(arr1);
// 	}
// 	else
// 	{
// 		printf("Memory allocation using ft_calloc failed.\n");
// 	}

// 	// Test case 2: Using calloc from the C library
// 	int *arr2 = (int *)calloc(num_elements, element_size);
// 	if (arr2)
// 	{
// 		printf("Memory allocated using calloc: ");
// 		for (size_t i = 0; i < num_elements; ++i)
// 		{
// 			printf("%d ", arr2[i]);
// 		}
// 		printf("\n");

// 		free(arr2);
// 	}
// 	else
// 	{
// 		printf("Memory allocation using calloc failed.\n");
// 	}

// 	return (0);
// }
