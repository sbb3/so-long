/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:13:19 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 15:36:41 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	draw_wall_floor(t_game *game, char c)
{
	if (c == '1')
		game->img = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width, \
		&game->img_height);
	else if (c == '0')
		game->img = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->img_width, \
		&game->img_height);
}

void	draw_collects(t_game *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, COLLECT, &game->img_width, \
	&game->img_height);
}

void	draw_exit(t_game *game)
{
	if (!collect_count(game->map))
		game->img = mlx_xpm_file_to_image(game->mlx, EXIT_OPEN, \
		&game->img_width, &game->img_height);
	else
		game->img = mlx_xpm_file_to_image(game->mlx, EXIT_CLOSE, \
		&game->img_width, &game->img_height);
}

void	draw_player(t_game *game, int y, int x)
{
	game->img = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->img_width, \
	&game->img_height);
	game->p_x = x;
	game->p_y = y;
}

void	rendering(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				draw_wall_floor(game, '1');
			else if (game->map[y][x] == '0')
				draw_wall_floor(game, '0');
			else if (game->map[y][x] == 'C')
				draw_collects(game);
			else if (game->map[y][x] == 'E')
				draw_exit(game);
			else if (game->map[y][x] == 'P')
				draw_player(game, y, x);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, \
			x * 48, y * 48);
			free_image(game);
		}
	}
}
