/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:09:37 by adouib            #+#    #+#             */
/*   Updated: 2022/02/07 13:08:15 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	main(int ac, const char *av[])
{
	t_game	game;

	if (ac != 2)
		quit(NULL, "Format: ./so_long <map name>.ber");
	parsing(av, &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		quit(&game, "Connection to the X-Window Server failed");
	game.mlx_win = mlx_new_window(game.mlx, game.map_width * IMG_WIDTH, \
		game.map_height * IMG_HEIGHT, "SO_LONG");
	if (!game.mlx_win)
		quit(&game, "New window initialization failed");
	rendering(&game);
	mlx_key_hook(game.mlx_win, event_helper, &game);
	mlx_hook(game.mlx_win, 17, 0L, red_cross_quit, &game);
	mlx_loop(game.mlx);
}
