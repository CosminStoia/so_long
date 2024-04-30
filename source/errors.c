/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:09:56 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/26 15:07:33 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_char_error(t_game *game)
{
	if (game->player != 1)
	{
		ft_printf("Error:\nNumber of players invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->exit != 1)
	{
		ft_printf("Error:\nNumber of exits invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->collectibles < 1)
	{
		ft_printf("Error:\nNumber of collectibles invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->rows < 3)
	{
		ft_printf("Error:\nInvalid map!");
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error(void)
{
	ft_printf("Error:\nInvalid walls!");
	exit(EXIT_FAILURE);
}

void	ft_map_error1(int fd)
{
	ft_printf("Error:\nMemory allocation failed!\n");
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_map_error2(t_game *game, int fd)
{
	free(game->map);
	close(fd);
	exit(EXIT_FAILURE);
}
