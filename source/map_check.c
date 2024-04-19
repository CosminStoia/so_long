/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:28:18 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/19 14:57:25 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check map dimensions (must be rectangular)
// Check all the characters in the map
// Function to validate the map (Calling ft_check_map_dimension and ft_check_character)

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
			return (-1);
		}
		rows++;
	}
	return (1);
}

int	ft_check_character_2(t_characters *count, char c)
{
	if (c == '\0')
	{
		perror("Error: NULL character found in the map!");
		return (-1);
	}
	if (c != WALL && c != PLAYER && c != EXIT && c != COLLECTIBLE
		&& c != BACKROUND)
	{
		perror("Error: Invalid characters");
		return (-1);
	}
	if (c == PLAYER)
		count->player++;
	else if (c == EXIT)
		count->exit++;
	else if (c == COLLECTIBLE)
		count->collectibles++;
	return (1);
}

int	ft_check_characters(char **map, int rows, int cols)
{
	int				i;
	int				j;
	char			c;
	t_characters	count;

	count = (t_characters){0, 0, 0};
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			c = map[i][j];
			ft_check_character_2(&count, c);
			j++;
		}
		i++;
	}
	if (count.player != 1)
	{
		perror("Error: Number of players invalid!");
		return (-1);
	}
	if (count.exit != 1)
	{
		perror("Error: Number of exits invalid!");
		return (-1);
	}
	if (count.collectibles < 1)
	{
		perror("Error: Invalid number of collectibles!");
		return (-1);
	}
	return (1);
}

int	validate_map(char **map)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	if (!ft_check_map_dimensions(map))
	{
		perror("Error: Map dimensions invalid");
		return (-1);
	}
	while (map[rows] != NULL)
	{
		cols = ft_strlen(map[rows]);
		rows++;
	}
	if (!ft_check_characters(map, rows, cols))
	{
		return (-1);
	}
	return (1);
}
