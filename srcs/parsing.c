/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:09:33 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 16:15:27 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**map_read(const char *av[], t_game *game)
{
	game->backup = NULL;
	game->map_fd = open(av[1], O_RDONLY, 0755);
	if (game->map_fd == -1)
		quit(NULL, "Map opening failed");
	game->line = get_next_line(game->map_fd);
	while (game->line)
	{
		if (*game->line == '\n')
			quit(NULL, "Map has an empty line");
		game->backup = ft_strjoin(game->backup, game->line);
		game->line = get_next_line(game->map_fd);
	}
	game->map = ft_split(game->backup, '\n');
	close(game->map_fd);
	return (game->map);
}

void	parsing(const char *av[], t_game *game)
{
	check_map_extension(av);
	game->map = map_read(av, game);
	if (!game->map)
		quit(NULL, "map is empty");
	check_walls(game->map, game);
	check_rectangle(game->map);
	check_characters(game->map, game);
}
