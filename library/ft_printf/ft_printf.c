/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:13 by nchok             #+#    #+#             */
/*   Updated: 2023/11/20 18:44:35 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_specifier(char c, va_list ap, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), counter);
	else if (c == 'p')
		ft_putptr(va_arg(ap, void *), counter);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), counter);
	else if (c == 'u')
		ft_unsignednbr(va_arg(ap, unsigned int), counter);
	else if (c == 'x')
		ft_puthexlower(va_arg(ap, unsigned int), counter);
	else if (c == 'X')
		ft_puthexupper(va_arg(ap, unsigned int), counter);
	else if (c == '%')
		ft_putchar('%', counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	va_start(ap, s);
	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_specifier(s[i], ap, &counter);
		}
		else
		{
			ft_putchar(s[i], &counter);
		}
		i++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	int count;
// 	int	lib_count;

// 	count = ft_printf("%x\n", 10);
// 	lib_count = printf("%x\n", 10);
// 	printf("%d\n", count);
// 	printf("%d\n", lib_count);
// 	return (0);
// }
