/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:34:44 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/21 13:50:26 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_check_texture(mlx_t *mlx, char c)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = NULL;
	if (c == '1')
		texture = mlx_load_png("./image_files/wall.png");
	else if (c == 'P')
		texture = mlx_load_png("./image_files/player.png");
	else if (c == 'C')
		texture = mlx_load_png("./image_files/collectible.png");
	else if (c == 'E')
		texture = mlx_load_png("./image_files/exit.png");
	else if (c == '0')
		texture = mlx_load_png("./image_files/stone.png");
	image = mlx_texture_to_image(mlx, texture);
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
				image = ft_check_texture(mlx, c);
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
