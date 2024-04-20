/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:00:08 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/20 12:09:02 by cstoia           ###   ########.fr       */
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

typedef struct s_game
{
	int		player;
	int		exit;
	int		collectibles;
	int		rows;
	int		cols;
	char	**map;
}			t_game;

void		free_map(char **map);
int			ft_open_and_read_file(char *input, t_game *game);
void		ft_render_image(mlx_t *mlx, t_game *game);
int			ft_check_map_dimensions(char **map);
int			ft_check_character_2(t_game *game, char c);
void		ft_char_error(t_game *game);
int			ft_check_characters(t_game *game);
int			ft_validate_map(t_game *game);

#endif