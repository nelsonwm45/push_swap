/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:12:47 by nchok             #+#    #+#             */
/*   Updated: 2024/05/24 14:57:43 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			if (!inside_word)
			{
				count++;
				inside_word = 1;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	pointer = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[pointer] == c)
		pointer++;
	while ((s[pointer + len] != c) && s[pointer + len])
		len++;
	next_word = ft_calloc(len + 1, sizeof(char));
	if (!next_word)
		return (NULL);
	while ((s[pointer] != c) && s[pointer])
		next_word[i++] = s[pointer++];
	next_word[i] = '\0';
	return (next_word);
}

char	**wordsplit(char *s, char c)
{
	int		word_count;
	char	**result_array;
	int		i;

	i = 0;
	word_count = count_words(s, c);
	if (!word_count)
		return (NULL);
	result_array = ft_calloc(word_count + 2, sizeof(char *));
	if (!result_array)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = ft_calloc(1, sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

char	**remodify_input(char **av)
{
	char	*str;
	char	**argv;
	int		i;

	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	i = 2;
	while (av[i])
	{
		str = joinstr(str, " ");
		str = joinstr(str, av[i]);
		i++;
	}
	argv = wordsplit(str, ' ');
	free(str);
	return (argv);
}
