/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:31 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/30 13:03:24 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		ft_open_and_read_file(argv[1], game);
		mlx = mlx_init((game->cols - 1) * 50, game->rows * 50, "so_long", true);
		if (!mlx)
		{
			ft_printf("Error:\nFailed to initialize window");
			exit(EXIT_FAILURE);
		}
		game->mlx = mlx;
		ft_render_image(mlx, game);
		mlx_key_hook(mlx, &ft_input, game);
		mlx_loop(mlx);
		mlx_terminate(game->mlx);
	}
	else
	{
		ft_printf("Error:\nInvalid number of arguments");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
