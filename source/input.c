/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:03:26 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/26 12:53:42 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_if1(t_game *game)
{
	if (game->map[game->position.y - 1][game->position.x] == 'E')
		if (game->count_collectible < game->collectibles)
			return ;
	if (game->map[game->position.y - 1][game->position.x] != '1')
	{
		game->position.y -= 1;
		mlx_image_to_window(game->mlx, game->image[1], game->position.x * 50,
			game->position.y * 50);
		mlx_image_to_window(game->mlx, game->image[4], game->position.x * 50,
			(game->position.y + 1) * 50);
		game->count++;
		ft_printf("Move: %d\n", game->count);
	}
}

void	ft_if2(t_game *game)
{
	if (game->map[game->position.y + 1][game->position.x] == 'E')
		if (game->count_collectible < game->collectibles)
			return ;
	if (game->map[game->position.y + 1][game->position.x] != '1')
	{
		game->position.y += 1;
		mlx_image_to_window(game->mlx, game->image[1], game->position.x * 50,
			game->position.y * 50);
		mlx_image_to_window(game->mlx, game->image[4], game->position.x * 50,
			(game->position.y - 1) * 50);
		game->count++;
		ft_printf("Move: %d\n", game->count);
	}
}

void	ft_if3(t_game *game)
{
	if (game->map[game->position.y][game->position.x - 1] == 'E')
		if (game->count_collectible < game->collectibles)
			return ;
	if (game->map[game->position.y][game->position.x - 1] != '1')
	{
		game->position.x -= 1;
		mlx_image_to_window(game->mlx, game->image[1], game->position.x * 50,
			game->position.y * 50);
		mlx_image_to_window(game->mlx, game->image[4], (game->position.x + 1)
			* 50, game->position.y * 50);
		game->count++;
		ft_printf("Move: %d\n", game->count);
	}
}

void	ft_if4(t_game *game)
{
	if (game->map[game->position.y][game->position.x + 1] == 'E')
		if (game->count_collectible < game->collectibles)
			return ;
	if (game->map[game->position.y][game->position.x + 1] != '1')
	{
		game->position.x += 1;
		mlx_image_to_window(game->mlx, game->image[1], game->position.x * 50,
			game->position.y * 50);
		mlx_image_to_window(game->mlx, game->image[4], (game->position.x - 1)
			* 50, game->position.y * 50);
		game->count++;
		ft_printf("Move: %d\n", game->count);
	}
}

void	ft_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	if (game->map[game->position.y][game->position.x] != 'E')
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			ft_if1(game);
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			ft_if2(game);
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			ft_if3(game);
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			ft_if4(game);
		if (game->map[game->position.y][game->position.x] == 'C')
		{
			game->count_collectible++;
			game->map[game->position.y][game->position.x] = '0';
		}
	}
	else
	{
		exit(0);
	}
}
