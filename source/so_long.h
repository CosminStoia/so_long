/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:00:08 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/17 23:28:12 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 712
# define HEIGHT 312

# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define BACKROUND '0'

typedef struct s_characters
{
	int	player;
	int	exit;
	int	collectibles;
}		t_characters;

int		ft_check_map_dimensions(char **map);
int		ft_check_c(t_characters *count, char c);
int		ft_check_characters(char **map, int rows, int cols);
int		validate_map(char **map);

#endif