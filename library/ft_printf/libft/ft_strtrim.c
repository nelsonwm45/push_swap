/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:42:24 by nchok             #+#    #+#             */
/*   Updated: 2023/10/26 16:50:49 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmpchrinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_cmpchrinset(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_cmpchrinset(s1[end - 1], set) == 1)
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

// int main (void)
// {
// 	char s1[] = "lorem ipsum dolor sit amet";

// 	printf("%s\n", ft_strtrim(s1, "te"));
// 	return (0);
// }
