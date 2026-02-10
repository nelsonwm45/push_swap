/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:30 by nchok             #+#    #+#             */
/*   Updated: 2023/10/27 16:19:20 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

// int main()
// {
//     const char *str = "Hello, world!";
//     int character_to_find = 'o';

//     char *custom_result = ft_strchr(str, character_to_find);
//     char *standard_result = strchr(str, character_to_find);

//     if (custom_result) {
//         printf("Custom ft_strchr found '%c' at position: %ld\n",
//				character_to_find, custom_result - str);
//     } else {
//         printf("Custom ft_strchr did not find '%c'\n", character_to_find);
//     }

//     if (standard_result) {
//         printf("Standard strchr found '%c' at position: %ld\n",
//				character_to_find, standard_result - str);
//     }
//		else {
//         printf("Standard strchr did not find '%c'\n", character_to_find);
//     }

//     return (0);
// }

// // war machine
// int main(void)
// {
// 	char		*str;
// 	char		str2[] = "bonjour";

// 	if (!(str = ft_strchr(str2, '\0')))
// 		ft_print_results("NULL");
// 	else
// 	{
// 		ft_print_result(str);
// 		if (str != str2 + 7)
// 			ft_print_result("\nReturn value is false");
// 	}
// }
