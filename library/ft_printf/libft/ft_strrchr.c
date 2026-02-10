/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:46 by nchok             #+#    #+#             */
/*   Updated: 2023/10/27 16:14:56 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				len;

	len = ft_strlen(s);
	str = (unsigned char *)s;
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "Hello";
//
// 	printf("%d\n", &str[0]);
// 	printf("%d\n", ft_strrchr(str, 'o'));
// 	printf("%d\n", ft_strrchr(str, '\0'));
// 	printf("%d\n", ft_strrchr(str, 'l'));
// 	printf("%d\n", ft_strrchr(str, 'z'));
// }
// int main()
// {
//     const char *str = "Hello, world!";
//     int character_to_find = 'o';

//     char *custom_result = ft_strrchr(str, character_to_find);
//     char *standard_result = strrchr(str, character_to_find);

//     if (custom_result) {
//         printf("Custom ft_strrchr found '%c' at position: %ld\n",
//			character_to_find, custom_result - str);
//     } else {
//         printf("Custom ft_strrchr did not find '%c'\n", character_to_find);
//     }

//     if (standard_result) {
//         printf("Standard strrchr found '%c' at position: %ld\n",
//			character_to_find, standard_result - str);
//     } else {
//         printf("Standard strrchr did not find '%c'\n", character_to_find);
//     }

//     return (0);
// }

// int main(void)
// {
// 	printf("%s\n", ft_strrchr("Hello", '\0'));
// 	printf("%s\n", strrchr("Hello", '\0'));
// 	return (0);
// }
