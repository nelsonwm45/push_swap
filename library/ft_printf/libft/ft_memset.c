/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:02:44 by nchok             #+#    #+#             */
/*   Updated: 2023/10/27 15:58:27 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	// Test Case 1: Setting integer values to a block of memory
// 	int intArray[5] = {1, 2, 3, 4, 5};
// 	size_t intSize = sizeof(intArray) / sizeof(int);
// 		// Calculate the number of elements in the array

// 	printf("Original Integer Array: ");
// 	for (size_t i = 0; i < intSize; i++)
// 	{
// 		printf("%d ", intArray[i]);
// 	}
// 	printf("\n");

// 	memset(intArray, 0, intSize * sizeof(int));

// 	printf("Library's Array:");
//     for (size_t i = 0; i < intSize; i++)
// 	{
// 		printf("%d ", intArray[i]);
// 	}
// 	printf("\n");

//     ft_memset(intArray, 0, intSize * sizeof(int));
// 		// Use correct size for the entire array

// 	printf("Modified Integer Array: ");
// 	for (size_t i = 0; i < intSize; i++)
// 	{
// 		printf("%d ", intArray[i]);
// 	}
// 	printf("\n");

// 	// Test Case 2: Setting characters to a block of memory
// 	char charArray[10] = "Hello";
// 	size_t charSize = sizeof(charArray) - 1;
// 		// Calculate the size without the null terminator

// 	printf("Original Char Array: %s\n", charArray);

// 	memset(charArray, 'X', charSize);

// 	printf("Library Char Array: %s\n", charArray);

// 	ft_memset(charArray, 'X', charSize); // Use correct size for the array

// 	printf("Modified Char Array: %s\n", charArray);

// 	// Test Case 3: Setting a single integer value
// 	int num = 42;
// 	printf("Original Number: %d\n", num);

// 	memset(&num, 0, sizeof(int));

// 	printf("Library Number: %d\n", num);

// 	ft_memset(&num, 0, sizeof(int)); // Use correct size for the integer

// 	printf("Modified Number: %d\n", num);

// 	return (0);
// }
