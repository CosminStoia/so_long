/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:09:56 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/23 10:46:52 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_char_error(t_game *game)
{
	if (game->player != 1)
	{
		perror("Error: Number of players invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->exit != 1)
	{
		perror("Error: Number of exits invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->collectibles < 1)
	{
		perror("Error: Number of collectibles invalid!");
		exit(EXIT_FAILURE);
	}
	if (game->rows < 3)
	{
		perror("Error: Invalid map!");
		exit(EXIT_FAILURE);
	}
}

void	ft_print_error(void)
{
	perror("Error: Invalid walls!");
	exit(EXIT_FAILURE);
}