/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:30:14 by nchok             #+#    #+#             */
/*   Updated: 2023/11/22 16:17:28 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTR_NULL "(nil)"
# elif defined(__APPLE__)
#  define PTR_NULL "0x0"
# endif

int		ft_printf(const char *s, ...);

// string (c, s, %)
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);

// numbers (d, i, u, x, X, p)
void	ft_putnbr(int num, int *counter);
void	ft_unsignednbr(unsigned int num, int *counter);
void	ft_puthexlower(unsigned long int num, int *counter);
void	ft_puthexupper(unsigned long int num, int *counter);
void	ft_putptr(void *ptr, int *counter);

#endif
