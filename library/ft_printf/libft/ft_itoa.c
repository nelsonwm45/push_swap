/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:25 by nchok             #+#    #+#             */
/*   Updated: 2023/10/30 14:26:31 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		if (n < 0)
			n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;
	int		sign;
	long	nbr;

	nbr = (long)n;
	int_len = count_digit(nbr);
	str = (char *)malloc(sizeof(char) * (int_len + 1));
	if (!str)
		return (NULL);
	sign = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	str[int_len] = '\0';
	while (int_len-- > 0)
	{
		str[int_len] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (sign == -1)
		*str = '-';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-21));
// }
