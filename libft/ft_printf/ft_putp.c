/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:31:53 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 17:29:46 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr(unsigned long n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static int	ft_putp_function(unsigned long n, int count)
{
	char	a;

	if (n >= 16)
		count = ft_putp_function(n / 16, count);
	if (count < 0)
		return (-1);
	n %= 16;
	a = ft_nbr(n);
	if (write(1, &a, 1) != 1)
		return (-1);
	return (count + 1);
}

int	ft_putp(unsigned long n)
{
	int	count;

	count = 2;
	if (write(1, "0x", 2) != 2)
		return (-1);
	return (ft_putp_function(n, count));
}
