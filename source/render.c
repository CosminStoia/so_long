/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:44 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/22 11:11:34 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_texture(mlx_t *mlx, t_game *game)
{
	int	i;

	i = 0;
	game->texture[0] = mlx_load_png("./image_files/wall.png");
	game->texture[1] = mlx_load_png("./image_files/player.png");
	game->texture[2] = mlx_load_png("./image_files/collectible.png");
	game->texture[3] = mlx_load_png("./image_files/exit.png");
	game->texture[4] = mlx_load_png("./image_files/stone.png");
	while (i < 5)
	{
		game->image[i] = mlx_texture_to_image(mlx, game->texture[i]);
		i++;
	}
}

mlx_image_t	*ft_check_image(mlx_t *mlx, t_game *game, char c)
{
	mlx_image_t	*image;

	ft_check_texture(mlx, game);
	if (c == '1')
		image = game->image[0];
	if (c == 'P')
		image = game->image[1];
	if (c == 'C')
		image = game->image[2];
	if (c == 'E')
		image = game->image[3];
	if (c == '0')
		image = game->image[4];
	return (image);
}
void	ft_render_image(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*image;
	int			x;
	int			y;
	char		c;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols - 1)
		{
			c = game->map[y][x];
			if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
				image = ft_check_image(mlx, game, c);
			else if (c == '\n')
			{
				y++;
				x = 0;
			}
			mlx_resize_image(image, 50, 50);
			mlx_image_to_window(mlx, image, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
