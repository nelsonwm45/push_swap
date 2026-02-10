/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:50:29 by nchok             #+#    #+#             */
/*   Updated: 2023/11/17 15:03:26 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *counter)
{
	int	results;

	results = 0;
	if (num == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (num < 0)
	{
		ft_putchar('-', counter);
		num *= -1;
		ft_putnbr(num, counter);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10, counter);
		ft_putnbr(num % 10, counter);
	}
	else
	{
		results += (num + '0');
		ft_putchar(results, counter);
	}
}

void	ft_unsignednbr(unsigned int num, int *counter)
{
	unsigned int	results;

	results = 0;
	if (num > 9)
	{
		ft_putnbr(num / 10, counter);
		ft_putnbr(num % 10, counter);
	}
	else
	{
		results += (num + '0');
		ft_putchar(results, counter);
	}
}

void	ft_puthexlower(unsigned long int num, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (num < 16)
	{
		ft_putchar(base[num], counter);
		return ;
	}
	ft_puthexlower(num / 16, counter);
	ft_putchar(base[num % 16], counter);
}

void	ft_puthexupper(unsigned long int num, int *counter)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (num < 16)
	{
		ft_putchar(base[num], counter);
		return ;
	}
	ft_puthexupper(num / 16, counter);
	ft_putchar(base[num % 16], counter);
}

void	ft_putptr(void *ptr, int *counter)
{
	unsigned long int	newptr;

	newptr = (unsigned long int)ptr;
	ft_putstr("0x", counter);
	if (!newptr)
	{
		ft_putchar('0', counter);
		return ;
	}
	ft_puthexlower(newptr, counter);
}
