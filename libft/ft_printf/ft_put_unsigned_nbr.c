/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:18:00 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 17:44:11 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr(unsigned int n)
{
	char	result;
	int		count;
	int		check;

	count = 0;
	if ((n / 10) != 0)
	{
		check = ft_put_unsigned_nbr(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	result = (n % 10) + '0';
	if (write(1, &result, 1) != 1)
		return (-1);
	return (count + 1);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	check;

	check = ft_putunbr(n);
	if (check == -1)
		return (-1);
	return (check);
}
