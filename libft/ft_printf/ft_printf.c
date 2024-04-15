/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:20:42 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 19:20:39 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_result(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == '%')
		return (ft_putchar('%'));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	else if (*str == 'p')
		return (ft_putp(va_arg(args, unsigned long)));
	else if (*str == 'x')
		return (ft_putx(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_putxxx(va_arg(args, unsigned int)));
	else
		return (-1);
}

static int	ft_parse_format(const char *str, va_list args)
{
	int	result;
	int	ret;

	result = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			ret = ft_result((str + 1), args);
			if (ret == -1)
				return (-1);
			result += ret;
			str++;
		}
		else
		{
			if (ft_putchar(*str) != 1)
				return (-1);
			result++;
		}
		str++;
	}
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	result;

	va_start(args, str);
	if (!str)
	{
		va_end(args);
		return (-1);
	}
	result = ft_parse_format(str, args);
	va_end(args);
	return (result);
}
