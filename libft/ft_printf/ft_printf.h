/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:21:21 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 19:16:05 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_put_unsigned_nbr(unsigned int n);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putp(unsigned long n);
int	ft_putstr(char *str);
int	ft_putx(unsigned int n);
int	ft_putxxx(unsigned int n);
int	ft_printf(const char *str, ...);

#endif
