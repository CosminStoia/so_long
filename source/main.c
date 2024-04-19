/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:31 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/19 14:55:14 by cstoia           ###   ########.fr       */
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
	int		i;
	char	**map;

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
			map = ft_split(line, '\n');
			free(line);
			if (map == NULL)
			{
				perror("Error: Memory allocation failed!\n");
				free(map);
				close(fd);
				return (-1);
			}
		}
		if (validate_map(map))
		{
			i = 0;
			while (map[i] != NULL)
			{
				ft_printf("%s\n", map[i]);
				i++;
			}
		}
		else if (!validate_map(map))
		{
			free(map);
			close(fd);
			return (-1);
		}
		free_map(map);
		close(fd);
	}
	return (1);
}
