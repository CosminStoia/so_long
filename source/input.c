/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:03:26 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/22 16:53:10 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (game->map[game->position.y][game->position.x] != 'E')
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		{
			if (game->map[game->position.y - 1][game->position.x] != '1')
			{
				game->position.y -= 1;
				mlx_image_to_window(game->mlx, game->image[1], game->position.x
					* 50, game->position.y * 50);
				mlx_image_to_window(game->mlx, game->image[4], game->position.x
					* 50, (game->position.y + 1) * 50);
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		{
			if (game->map[game->position.y + 1][game->position.x] != '1')
			{
				game->position.y += 1;
				mlx_image_to_window(game->mlx, game->image[1], game->position.x
					* 50, game->position.y * 50);
				mlx_image_to_window(game->mlx, game->image[4], game->position.x
					* 50, (game->position.y - 1) * 50);
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		{
			if (game->map[game->position.y][game->position.x - 1] != '1')
			{
				game->position.x -= 1;
				mlx_image_to_window(game->mlx, game->image[1], game->position.x
					* 50, game->position.y * 50);
				mlx_image_to_window(game->mlx, game->image[4], (game->position.x
						+ 1) * 50, game->position.y * 50);
			}
		}
		if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		{
			if (game->map[game->position.y][game->position.x + 1] != '1')
			{
				game->position.x += 1;
				mlx_image_to_window(game->mlx, game->image[1], game->position.x
					* 50, game->position.y * 50);
				mlx_image_to_window(game->mlx, game->image[4], (game->position.x
						- 1) * 50, game->position.y * 50);
			}
		}
	}
}
