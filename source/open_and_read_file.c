/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_read_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:51:06 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/26 15:23:32 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_error(void)
{
	ft_printf("Error:\nInvalid file");
	exit(EXIT_FAILURE);
}

void	ft_count_rows_and_cols(t_game *game, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] == '\n')
	{
		ft_printf("Error:\nInvalid map!");
		exit(EXIT_FAILURE);
	}
	if (len > game->cols)
		game->cols = len;
	game->rows++;
}

void	ft_map_error3(t_game *game, int fd)
{
	if (game->map == NULL)
		ft_map_error1(fd);
	if (game->mapcopy == NULL)
		ft_map_error1(fd);
	if (!ft_validate_map(game))
		ft_map_error2(game, fd);
}

int	ft_open_and_read_file(char *input, t_game *game)
{
	int		fd;
	char	*line;
	char	*concatenated_lines;

	concatenated_lines = ft_calloc(1, 1);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		ft_file_error();
	line = get_next_line(fd);
	while (line != NULL)
	{
		concatenated_lines = ft_strjoin_and_free(concatenated_lines, line);
		free(line);
		ft_count_rows_and_cols(game, line);
		line = get_next_line(fd);
	}
	game->map = ft_split(concatenated_lines, '\n');
	game->mapcopy = ft_split(concatenated_lines, '\n');
	free(concatenated_lines);
	ft_map_error3(game, fd);
	close(fd);
	return (EXIT_SUCCESS);
}
