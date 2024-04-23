/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:46:41 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/23 13:17:49 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **tab, t_game *game, t_position *pos)
{
	if (pos->x < 0 || pos->y < 0 || tab[pos->y][pos->x] == '1')
		return ;
	if (tab[pos->y][pos->x] == 'C')
		game->flood_count.c++;
	if (tab[pos->y][pos->x] == 'P')
		game->flood_count.p++;
	if (tab[pos->y][pos->x] == 'E')
		game->flood_count.e++;
	tab[pos->y][pos->x] = '1';
	(void)game;
	ft_flood_fill(tab, game, &(t_position){pos->x, pos->y - 1});
	ft_flood_fill(tab, game, &(t_position){pos->x, pos->y + 1});
	ft_flood_fill(tab, game, &(t_position){pos->x - 1, pos->y});
	ft_flood_fill(tab, game, &(t_position){pos->x + 1, pos->y});
}

int	ft_check_flood(t_game *game)
{
	ft_flood_fill(game->mapcopy, game, &game->position);
	if (game->flood_count.p != 1 || game->flood_count.e != 1
		|| game->flood_count.c != game->collectibles)
		return (-1);
	return (1);
}
