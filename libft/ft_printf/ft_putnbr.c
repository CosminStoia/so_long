/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:11:12 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 14:38:31 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(int n, int *count)
{
	char	result;

	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*count += 11;
		return (11);
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		(*count)++;
	}
	if (n >= 10)
		if (ft_putnbr_recursive(n / 10, count) == -1)
			return (-1);
	result = (n % 10) + '0';
	if (write(1, &result, 1) == -1)
		return (-1);
	(*count)++;
	return (*count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (ft_putnbr_recursive(n, &count) == -1)
		return (-1);
	return (count);
}
