/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:00:08 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/22 17:15:05 by cstoia           ###   ########.fr       */
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

typedef struct s_init_pos
{
	int				x;
	int				y;
}					t_init_pos;

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;
typedef struct s_game
{
	mlx_t			*mlx;
	int				player;
	int				exit;
	int				collectibles;
	int				rows;
	int				cols;
	char			**map;
	mlx_image_t		*image[5];
	mlx_texture_t	*texture[5];
	t_position		position;
	int				count;
	int				count_collectible;
}					t_game;

int					ft_open_and_read_file(char *input, t_game *game);
int					ft_check_map_dimensions(char **map);
int					ft_check_character_2(t_game *game, char c, int i, int j);
void				ft_char_error(t_game *game);
int					ft_check_characters(t_game *game);
int					ft_validate_map(t_game *game);
void				ft_check_texture(mlx_t *mlx, t_game *game);
mlx_image_t			*ft_check_image(mlx_t *mlx, t_game *game, char c);
void				ft_render_image(mlx_t *mlx, t_game *game);
void				ft_file_error(void);
void				ft_count_rows_and_cols(t_game *game, char *line);
void				ft_map_error1(int fd);
void				ft_map_error2(t_game *game, int fd);
void				ft_input(void *param);
#endif