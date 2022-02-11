/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:13:03 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 16:13:27 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	print_moves(void)
{
	static int	moves;

	moves++;
	printf("steps : %d\n", moves);
}

int	is_barriernext(t_game *game, char c)
{
	int	y;
	int	x;

	y = game->p_y;
	x = game->p_x;
	if (c == 'w')
		y--;
	else if (c == 's')
		y++;
	else if (c == 'a')
		x--;
	else if (c == 'd')
		x++;
	if (game->map[y][x] == 'E' && !collect_count(game->map))
		quit(game, NULL);
	if (game->map[y][x] == '1' || game->map[y][x] == 'E')
		return (1);
	print_moves();
	return (0);
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == W_KEY && !is_barriernext(game, 'w'))
		game->p_y--;
	else if (keycode == S_KEY && !is_barriernext(game, 's'))
		game->p_y++;
	else if (keycode == A_KEY && !is_barriernext(game, 'a'))
		game->p_x--;
	else if (keycode == D_KEY && !is_barriernext(game, 'd'))
		game->p_x++;
}

void	move_helper(int keycode, t_game *game)
{
	game->map[game->p_y][game->p_x] = '0';
	move_player(keycode, game);
	game->map[game->p_y][game->p_x] = 'P';
	rendering(game);
}

int	event_helper(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		quit(game, NULL);
	else
		move_helper(keycode, game);
	return (0);
}
