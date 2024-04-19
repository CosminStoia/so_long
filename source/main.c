/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:31 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/19 21:19:20 by cstoia           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**map;
	char	*concatenated_lines;
	int		i;

	map = NULL;
	line = NULL;
	concatenated_lines = ft_calloc(1, 1);
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error: Failed to open file");
			return (-1);
		}
		while ((line = get_next_line(fd)) != NULL)
		{
			concatenated_lines = ft_strjoin_and_free(concatenated_lines, line);
			free(line);
		}
		map = ft_split(concatenated_lines, '\n');
		free(concatenated_lines);
		if (map == NULL)
		{
			perror("Error: Memory allocation failed!\n");
			close(fd);
			return (-1);
		}
		if (!ft_validate_map(map))
		{
			free(map);
			close(fd);
			return (-1);
		}
		i = 0;
		while (map[i] != NULL)
		{
			ft_printf("%s", map[i]);
			i++;
		}
		free_map(map);
		close(fd);
	}
	return (0);
}
