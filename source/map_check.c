/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:28:18 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/23 13:17:22 by cstoia           ###   ########.fr       */
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

int	ft_check_character_2(t_game *game, char c, int i, int j)
{
	if (c != '1' && c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '\0')
	{
		perror("Error: Invalid characters");
		exit(EXIT_FAILURE);
	}
	if (c == 'P')
	{
		game->position.x = i;
		game->position.y = j;
		game->player++;
	}
	else if (c == 'E')
		game->exit++;
	else if (c == 'C')
		game->collectibles++;
	return (1);
}

void	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (x < game->cols)
	{
		if (game->map[0][x - 1] != '1')
			ft_print_error();
		x++;
	}
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->cols - 2] != '1')
			ft_print_error();
		y++;
	}
	x = 1;
	while (x < game->cols)
	{
		if (game->map[game->rows - 1][x - 1] != '1')
			ft_print_error();
		x++;
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
			ft_check_character_2(game, c, j, i);
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
	ft_check_walls(game);
	if (ft_check_flood(game) < 0)
	{
		perror("Error: Flood fill failed!");
		exit(EXIT_FAILURE);
	}
	return (1);
}
