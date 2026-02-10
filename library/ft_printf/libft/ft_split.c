/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:52:02 by nchok             #+#    #+#             */
/*   Updated: 2023/11/06 11:52:47 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char	*ft_cpy(char const *s, size_t len)
{
	size_t	i;
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_array(char **split, size_t word_index)
{
	while (word_index >= 0)
	{
		free(split[word_index]);
		word_index--;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	num_words = ft_countwords(s, c);
	split = malloc(sizeof(char *) * (num_words + 1));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < num_words)
	{
		while (*s && *s == c)
			s++;
		split[i] = ft_cpy(s, ft_wordlen(s, c));
		if (!split[i])
		{
			ft_free_array(split, i);
			return (0);
		}
		s += ft_wordlen(s, c);
	}
	split[num_words] = NULL;
	return (split);
}

// int main(void)
// {
// 	// char str[] = "Hello This is 42KL";
// 	char **result;
// 	size_t	i;

// 	i = 0;
// 	result = ft_split("          ", ' ');
// 	printf("%zu\n", ft_countwords("          ", ' '));
// 	while (result[i] != 0)
// 	{
// 		printf("[%s]\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	char	*string;
// 	size_t	i;
// 	char	**result;

// 	string = "      split       this for   me  !       ";
// 	// char	**expected = ((char*[6]){"split", "this", "for", "me", "!", NULL});
// 	result = ft_split(string, ' ');
// 	i = 0;
// 	while (result[i] != 0)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
