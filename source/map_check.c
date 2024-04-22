/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:28:18 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/22 11:10:03 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check map dimensions (must be rectangular)
// Check all the characters in the map
// Function to validate the map 
//(Calling ft_check_map_dimension and ft_check_character)

int	ft_check_map_dimensions(char **map)
{
	int	rows;
	int	cols;
	int	current_col;

	rows = 0;
	cols = 0;
	while (map[rows] != NULL)
	{
		current_col = ft_strlen(map[rows]);
		if (cols == 0)
		{
			cols = current_col;
		}
		else if (current_col != cols)
		{
			perror("Error: Map dimensions invalid");
			exit(EXIT_FAILURE);
		}
		rows++;
	}
	return (1);
}

int	ft_check_character_2(t_game *game, char c)
{
	if (c != '1' && c != 'P' && c != 'E' && c != 'C'
		&& c != '0' && c != '\0')
	{
		perror("Error: Invalid characters");
		exit(EXIT_FAILURE);
	}
	if (c == 'P')
		game->player++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'C')
		game->collectibles++;
	return (1);
}

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
		perror("Error: Invalid number of collectibles!");
		exit(EXIT_FAILURE);
	}
}

int	ft_check_characters(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			c = game->map[i][j];
			ft_check_character_2(game, c);
			j++;
		}
		i++;
	}
	ft_char_error(game);
	return (1);
}

int	ft_validate_map(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	if (!ft_check_map_dimensions(game->map))
	{
		return (-1);
	}
	while (game->map[rows] != NULL)
	{
		cols = ft_strlen(game->map[rows]);
		rows++;
	}
	if (!ft_check_characters(game))
	{
		return (-1);
	}
	return (1);
}
