/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:31 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/20 16:11:01 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_open_and_read_file(char *input, t_game *game)
{
	int		fd;
	char	*line;
	char	*concatenated_lines;
	int		len;
	int		i;

	line = NULL;
	concatenated_lines = ft_calloc(1, 1);
	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Failed to open file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		concatenated_lines = ft_strjoin_and_free(concatenated_lines, line);
		free(line);
		len = ft_strlen(line);
		if (len > game->cols)
			game->cols = len;
		game->rows++;
	}
	game->map = ft_split(concatenated_lines, '\n');
	free(concatenated_lines);
	if (game->map == NULL)
	{
		perror("Error: Memory allocation failed!\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (game->map[i] != NULL)
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
	if (!ft_validate_map(game))
	{
		free(game->map);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

void	ft_render_image(mlx_t *mlx, t_game *game)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
	int				x;
	int				y;
	char			c;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			c = game->map[y][x];
			if (c == '1')
			{
				texture = mlx_load_png("./image_files/wall.png");
				image = mlx_texture_to_image(mlx, texture);
			}
			else if (c == 'P')
			{
				texture = mlx_load_png("./image_files/player.png");
				image = mlx_texture_to_image(mlx, texture);
			}
			else if (c == 'C')
			{
				texture = mlx_load_png("./image_files/collectible.png");
				image = mlx_texture_to_image(mlx, texture);
			}
			else if (c == 'E')
			{
				texture = mlx_load_png("./image_files/exit.png");
				image = mlx_texture_to_image(mlx, texture);
			}
			else
			{
				texture = mlx_load_png("./image_files/stone.png");
				image = mlx_texture_to_image(mlx, texture);
			}
			mlx_image_to_window(mlx, image, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_game	*game;

	if (argc > 1)
	{
		game = ft_calloc(1, sizeof(t_game));
		ft_open_and_read_file(argv[1], game);
		if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", true)))
		{
			perror("Error: Failed to initialize window");
			exit(EXIT_FAILURE);
		}
		ft_render_image(mlx, game);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
	{
		perror("Error: Invalid number of arguments");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
