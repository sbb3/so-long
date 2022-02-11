/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:12:48 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 16:14:26 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_characters(char *map[], t_game *game)
{
	int	i;

	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	i = -1;
	while (++i < map_height(map) - 1)
	{
		game->player += search_map(map[i], 'P');
		game->collect += search_map(map[i], 'C');
		game->exit += search_map(map[i], 'E');
	}
	if (game->player != 1)
		quit(NULL, "Must be 1 player in the map no more no less");
	if (game->collect == 0)
		quit(NULL, "Must be at least 1 collect in the map");
	if (game->exit == 0)
		quit(NULL, "Must be at least 1 exit in the map");
}

void	check_rectangle(char *map[])
{
	int	i;

	i = -1;
	while (map[++i])
		if (map_width(map[0]) != map_width(map[i]))
			quit(NULL, "Map is not rectangle");
}

void	check_walls(char *map[], t_game *game)
{
	int	i;

	game->map_width = map_width(map[0]);
	game->map_height = map_height(map);
	if (!ft_strchr(map[0], '1') || !ft_strchr(map[game->map_height - 1], '1'))
		quit(NULL, "Map is not surrendered by upper or lower walls");
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][game->map_width - 1] != '1')
			quit(NULL, "Map is not surrendered by left or right walls");
}

void	check_map_extension(const char *av[])
{
	if (!ft_strrstr(av[1], ".ber", 4))
		quit(NULL, "Map not .ber extension file");
}
