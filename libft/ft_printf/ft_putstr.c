/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:25:08 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 13:32:13 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	size_t	ret;
	size_t	str_len;

	if (!str)
	{
		ret = write(1, "(null)", 6);
		if (ret != 6)
			return (-1);
		return (6);
	}
	str_len = ft_strlen(str);
	ret = write(1, str, str_len);
	if (ret != str_len)
		return (-1);
	return (ret);
}
